#ifndef PIXELMATRIX_H
#define PIXELMATRIX_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Pixel.hpp"

struct Size {
    int height;
    int width;
};

class PixelMatrix {
    public:
        vector<vector<Pixel*>> image_vect;

        PixelMatrix();
        ~PixelMatrix();

        bool setPixel(int h, int w, Pixel *p);
        Pixel* getPixel(int h, int w);
        void processPixels(void (*processFunction)(Pixel *));
        Pixel* averageColor();
        bool pixIsInImage(int h, int w);
        bool pushPixel(int h, Pixel *p);
};
#endif // !PIXELMATRIX_H