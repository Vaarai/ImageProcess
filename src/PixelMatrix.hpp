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
        bool pushPixel(int h, Pixel *p);
        Pixel* getPixel(int h, int w);
        bool pixIsInImage(int h, int w);
        Color averageColor();
        void processPixels(void (*processFunction)(Pixel *));
};
#endif // !PIXELMATRIX_H