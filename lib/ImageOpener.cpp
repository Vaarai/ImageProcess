#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <boost/algorithm/string.hpp>

#include "ImageOpener.hpp"
#include "Image.hpp"


ImageOpener::ImageOpener() {
}

ImageOpener::~ImageOpener() {
}

string ImageOpener::getExtension(string path) {
    return path.substr(path.find_last_of('.') + 1);
}

string ImageOpener::openFile(string path){
    string line;
    ifstream file (path);
    string s = "";
    if (file.is_open())
    {
        while ( getline(file,line) )
        {
            s += line + '\n';
        }
        file.close();
    }

    else{
        cout << "FAIL\nUnable to open file: " << path << "\n"; 
        return "";
    }

    return s;
}

Image ImageOpener::openImage(string path){
    string extension = this->getExtension(path);
    if(extension == "ppm") {
        cout << "Opening " << path << "... ";
        return this->convertPpmToImage(this->openFile(path));
    } else {
        cout << "FAIL\nThis file is not a .ppm !\n";
        exit(-1);
    }
}

Image ImageOpener::convertPpmToImage(string textFile){
    string ppmType = textFile.substr(0, 2);
    if(ppmType == "P3") {
        // Get size
        cout << "OK\n";
        int fileWidth = atoi(textFile.substr(3, textFile.find(" ")).c_str());
        int fileHeight = atoi(textFile.substr(textFile.find(" "), textFile.find("\n", 3)).c_str());
        cout << "Size: H=" << fileHeight << " W=" << fileWidth << "\nSpliting file... ";

        // Remove header to process content
        unsigned int pos=0;
        for(int i=0; i<3; i++) {
            pos = textFile.find('\n', pos+1);
        }
        textFile = textFile.substr(pos+1);
        
        // Start conversion by split on space
        boost::replace_all(textFile, " \n", " ");
        std::vector<std::string> contentVector;
        boost::split(contentVector, textFile, [](char c){return c == ' ';});

        // Put each value in pixel, and each pixel in image 
        cout << "OK\nLoading image object... ";
        unsigned int i=0;
        unsigned int h=-1;
        pixel *currentPixel;
        Image outputImage;
        for (vector<string>::iterator it = contentVector.begin(); it != contentVector.end(); ++it)
        {
            int value = atoi(it->c_str());
            switch (i%3) {
                case 0: // Start of the pixel with RED
                    currentPixel = new pixel;
                    currentPixel->red = value;
                    if(i % ((fileWidth)*3) == 0) h++;
                    break;
                case 1: // GREEN value
                    currentPixel->green = value;
                    break;
                case 2: // End of the pixel with BLUE and push it in the image
                    currentPixel->blue = value;
                    if(!outputImage.pushPixel(h, currentPixel)) cout << "Fail to generate pixels";
                    break;
            }
            i++;
        }
        cout << "OK\n";
        return outputImage;
    }
    // If it isn't a P3 ppm file return void image
    Image i;
    return i;
}
