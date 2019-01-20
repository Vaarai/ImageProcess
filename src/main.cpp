#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Image.hpp"
#include "Pixel.hpp"

void toto(Pixel *p) {
    int max = p->averageColorValue();
    if(max < 150) p->setColor(RED, 255);
}

int main(void) {
    Image *im = new Image("./data/jaina.ppm");
    im->processPixels(&toto);
    im->saveImage("a.ppm");
}