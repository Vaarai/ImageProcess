#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <boost/algorithm/string.hpp>

#include "Image.hpp"
#include "Pixel.hpp"

Image::Image() {
}

Image::Image(string path) {
    this->openImage(path);
}

Image::~Image() {
}

string Image::getExtension(string path) {
    return path.substr(path.find_last_of('.') + 1);
}

string Image::openFileRead(string path){
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

void Image::saveImage(string path) {
    string header = "P3\n" + 
                    to_string(this->imageSize.width) + " " + to_string(this->imageSize.height) + "\n" +
                    to_string(this->saturation) + "\n";
    string content = "";

    for (vector<vector<Pixel*>>::iterator it_vect = this->image_vect.begin(); it_vect != this->image_vect.end(); ++it_vect) {
        for (vector<Pixel*>::iterator it_pix = it_vect->begin(); it_pix != it_vect->end(); ++it_pix) {
            Pixel p = **it_pix;
            content += p.getColorString() + " ";
        }
        content += "\n";
    }

    cout << "Writing output in " << path << "... ";
    ofstream file (path);
    if (file.is_open())
    {
        file << header << content;
        file.close();
        cout << "OK\n";
    }else{
        cout << "FAIL\nUnable to save output\n"; 
    }
}

void Image::openImage(string path){
    string extension = this->getExtension(path);
    if(extension == "ppm") {
        cout << "Opening " << path << "... ";
        this->convertPpmToImage(this->openFileRead(path));
    } else {
        cout << "FAIL\nThis file is not a .ppm !\n";
        exit(-1);
    }
}

void Image::convertPpmToImage(string textFile){
    string ppmType = textFile.substr(0, 2);
    if(ppmType == "P3") {
        cout << "OK\n";
        // Get size and saturation
        this->imageSize.width  = atoi(textFile.substr(3, textFile.find(" ")).c_str());
        this->imageSize.height = atoi(textFile.substr(textFile.find(" "), textFile.find("\n", 3)).c_str());
        this->saturation = atoi(textFile.substr(textFile.find("\n", 3), textFile.find("\n", textFile.find("\n", 3))).c_str());
        cout << "Size: H=" << this->imageSize.height << " W=" << this->imageSize.width << "\nSpliting file... ";

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

        // Put each value in Pixel, and each Pixel in image 
        cout << "OK\nLoading image object... ";
        unsigned int i=0;
        unsigned int h=-1;
        Pixel *currentPixel;
        for (vector<string>::iterator it = contentVector.begin(); it != contentVector.end(); ++it)
        {
            int value = atoi(it->c_str());
            switch (i%3) {
                case 0: // Start of the Pixel with RED
                    currentPixel = new Pixel();
                    currentPixel->setColorRed(value);
                    if(i % ((this->imageSize.width)*3) == 0) h++;
                    break;
                case 1: // GREEN value
                    currentPixel->setColorGreen(value);
                    break;
                case 2: // End of the Pixel with BLUE and push it in the image
                    currentPixel->setColorBlue(value);
                    if(!this->pushPixel(h, currentPixel)) cout << "Fail to generate Pixels";
                    break;
            }
            i++;
        }
        cout << "OK\n";
    }
}

void Image::processPixelsAvg(void (*processFunction)(Pixel*, PixelMatrix*), int ray){
    
}