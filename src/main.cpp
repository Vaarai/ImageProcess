#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Image.hpp"
#include "Pixel.hpp"

Color cartoon(PixelMatrix m) {
    int h = m.image_vect.size()/2 + 1;
    int w = m.image_vect[0].size()/2 + 1;
    Pixel *center_pix = m.getPixel(h, w);

    Color c = m.averageColor();
    int gray_scale = (c.red+c.green+c.blue)/4;

    if(center_pix->grayScale().red < gray_scale) {
        c = {255, 0, 0};
    } else if(center_pix->grayScale().red > 1.4*gray_scale) {
        c = {60, 60, 255};
    } else {
        c = {rand()%256, rand()%256, rand()%256};
    }

    return c;
}

Color blurre(PixelMatrix m) {
        return m.averageColor();
}



void toto(Pixel* p) {
    Pixel p1 = Pixel::randomPixel();
    Pixel p2 = Pixel(p1.negative());

    int diff1 = p1.averageColorValue()-p->averageColorValue();
    int diff2 = p2.averageColorValue()-p->averageColorValue();

    Color c = (diff1 < diff2)? p1.getColor() : p2.getColor(); 

    p->setColor(c);
}


int main(void) {
    Image *im = new Image("./data/dark_city.ppm");
    im->processPixelsAround(&cartoon, 4);
    //im->processPixelsAround(&blurre, 3);
    im->saveImage("a.ppm");
}