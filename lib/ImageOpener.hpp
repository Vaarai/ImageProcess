#ifndef IMAGEOPENER_H
#define IMAGEOPENER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Image.hpp"

class ImageOpener {
private:
    string getExtension(string path);
    string openFile(string path);
    Image convertPpmToImage(string textFile);

public:
    ImageOpener();
    ~ImageOpener();
    Image openImage(string path);
};

#endif // !IMAGEOPENER_H