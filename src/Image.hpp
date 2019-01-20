#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "PixelMatrix.hpp"

class Image : public PixelMatrix {
    private:
        //vector<vector<Pixel*>> image_vect;
        Size imageSize;
        int saturation;

        string getExtension(string path);
        string openFileRead(string path);
        void convertPpmToImage(string textFile);

    public:
        Image();
        Image(string path);
        ~Image();

        void openImage(string path);
        void saveImage(string path);

        void processPixelsAvg(Color (*processFunction)(PixelMatrix), int ray);
};
#endif // !IMAGE_H