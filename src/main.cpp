#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Image.hpp"
#include "Pixel.hpp"

void toto(Pixel *p) {

    p->setColor(p->maxColorValue());

    /*
    int average = (p->blue + p->green + p->red)/3;
    int th = 100;
    int r = (p->red >= th) ? 200 : 50;
    int g = (p->green >= th) ? 200 : 50;
    int b = (p->blue >= th) ? 200 : 50;
    p->red = r;
    p->green = g;
    p->blue = b;
    int max = maximumColor(*p);
    p->red = ((max-p->red<th)?(max==p->red)?max:p->red/2:0);
    p->green = ((max-p->green<th)?(max==p->green)?max:p->red/2:0);
    p->blue = ((max-p->blue<th)?(max==p->blue)?max:p->red/2:0);
    */
}

int main(void) {
    Image *im = new Image("./data/jaina.ppm");
    im->processPixels(&toto);
    im->saveImage("a.ppm");
}