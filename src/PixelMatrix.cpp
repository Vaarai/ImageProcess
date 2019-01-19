#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <boost/algorithm/string.hpp>

#include "PixelMatrix.hpp"
#include "Pixel.hpp"

PixelMatrix::PixelMatrix() {
}

PixelMatrix::~PixelMatrix() {
}

bool PixelMatrix::pushPixel(int h, Pixel *p){
    if(h >= (int)(image_vect.size())){
        vector<Pixel*> v;
        this->image_vect.push_back(v);
    }

    // push back the Pixel on the h line
    this->image_vect[h].push_back(p);

    return 1;
}

bool PixelMatrix::setPixel(int h, int w, Pixel *p){
    if(this->pixIsInImage(h, w)) return 0;

    this->image_vect[h][w] = p;
    return 1;
}

Pixel* PixelMatrix::getPixel(int h, int w){
    if(this->pixIsInImage(h, w)) return this->image_vect[h][w];
    Pixel* p = new Pixel(-1);
    return p;
}

bool PixelMatrix::pixIsInImage(int h, int w){
    if(h >= (int)(this->image_vect.size())) return 0;
    if(w >= (int)(this->image_vect[0].size())) return 0;
    if(h < 0 or w < 0) return 0;
    return 1;
}


void PixelMatrix::processPixels(void (*processFunction)(Pixel *)){
    for (vector<vector<Pixel*>>::iterator it_vect = this->image_vect.begin(); it_vect != this->image_vect.end(); ++it_vect) {
        for (vector<Pixel*>::iterator it_pix = it_vect->begin(); it_pix != it_vect->end(); ++it_pix) {
            Pixel *p = *it_pix;
            (*processFunction)(p);
        }
    }
}

Color PixelMatrix::averageColor() {
    double i = 0;
    double red = 0;
    double green = 0;
    double blue = 0;
    for (vector<vector<Pixel*>>::iterator it_vect = this->image_vect.begin(); it_vect != this->image_vect.end(); ++it_vect) {
        for (vector<Pixel*>::iterator it_pix = it_vect->begin(); it_pix != it_vect->end(); ++it_pix) {
            i++;
            Pixel *p = *it_pix;
            red += p->getColor().red;
            green += p->getColor().green;
            blue += p->getColor().blue;
        }
    }
    Color out_color;
    out_color.red = (int)(red/i);
    out_color.green = (int)(green/i);
    out_color.blue = (int)(blue/i);
    //cout << out_pix.red << " " << out_pix.green << " " << out_pix.blue;
    return out_color;
}