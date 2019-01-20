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
    int gray_scale = (c.red+c.green+c.blue)/3;

    if(center_pix->grayScale().red < gray_scale) {
        c = {0, 0, 0};
    } 

    return c;
}


Color blurre(PixelMatrix m) {
    return m.averageColor();
}



void toto(Pixel* p) {
    Pixel p1 = Pixel::randomPixel();
    Pixel p2 = Pixel::randomPixel();

    int diff1 = p1.averageColorValue()-p->averageColorValue();
    int diff2 = p2.averageColorValue()-p->averageColorValue();

    Color c = (diff1 < diff2)? p1.getColor() : p2.getColor(); 

    p->setColor(c);
}


int main(void) {
    Image *im = new Image("./data/town.ppm");
    im->processPixels(&toto);
    im->processPixelsAround(&blurre, 1);
    im->processPixelsAround(&blurre, 1);
    im->processPixelsAround(&blurre, 1);
    //im->processPixelsAround(&cartoon, 2);
    im->saveImage("a.ppm");
}