#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Image.hpp"
#include "Pixel.hpp"

Color toto(PixelMatrix m) {
    int h = m.image_vect.size()/2 + 1;
    int w = m.image_vect[0].size()/2 + 1;
    Pixel *center_pix = m.getPixel(h, w);
    Color c = m.averageColor();
    int gray_scale = (c.red+c.green+c.blue)/3;
    if(center_pix->grayScale().red < gray_scale) {
        c = {0, 0, 0};
    }
    return c;
}

int main(void) {
    Image *im = new Image("./data/town.ppm");
    im->processPixelsAvg(&toto, 3);
    im->saveImage("a.ppm");
}