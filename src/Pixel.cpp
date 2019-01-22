#include <iostream>
using namespace std;

#include "Pixel.hpp"

/* Some work to be done later
string& operator << (string& s, Pixel p) {
    Color c = p.getColor();
    int r = c.red;
    int g = c.green;
    int b = c.blue;
    return s << r << ' ' << g << ' ' << b;
}

ostream& operator << (std::ostream& os, Pixel p) {
    string s = "";
    s << p;
    return os << s;
}
*/

Pixel::Pixel() {

}

Pixel::Pixel(int averageValue) {
    this->pixelColor.red = averageValue;
    this->pixelColor.green = averageValue;
    this->pixelColor.blue = averageValue;
}

Pixel::Pixel(int r, int g, int b) {
    this->pixelColor.red = r;
    this->pixelColor.green = g;
    this->pixelColor.blue = b;
}

Pixel::Pixel(Color c) {
    this->pixelColor = c;
}

Pixel::~Pixel() {

}

Pixel Pixel::randomPixel() {
    Pixel p;
    p = Pixel(rand()%256, rand()%256, rand()%256);
    return p;
}

Color Pixel::getColor() {
    return this->pixelColor;
}

string Pixel::getColorString() {
    return to_string(this->pixelColor.red) + " " + to_string(this->pixelColor.green) + " " + to_string(this->pixelColor.blue);
}

void Pixel::setColor(int value) {
    this->pixelColor.red = value;
    this->pixelColor.green = value;
    this->pixelColor.blue = value;
}

void Pixel::setColor(int r, int g, int b) {
    this->pixelColor.red = r;
    this->pixelColor.green = g;
    this->pixelColor.blue = b;
}

void Pixel::setColor(ColorE color_type, int value) {
    switch (color_type)
    {
        case RED:
            this->pixelColor.red = value;
            break;
        case GREEN:
            this->pixelColor.green = value;
            break;
        case BLUE:
            this->pixelColor.blue = value;
            break;
    }
}

void Pixel::setColor(Color c) {
    this->pixelColor = c;
}

Color Pixel::grayScale() {
    int average = this->averageColorValue();
    Color c;
    c.red = average; c.green = average; c.blue = average;
    return c;
}

Color Pixel::negative() {
    Color c = this->getColor();
    c.red = 255-c.red;
    c.green = 255-c.green;
    c.blue = 255-c.blue;
    return c;
}

ColorE Pixel::maxColorType() {
    const int r = this->pixelColor.red;
    const int g = this->pixelColor.green;
    const int b = this->pixelColor.blue;

    int max = (r<g)?g:r;
    max = ((b)?b:max);
    
    if(max == r) return ColorE::RED;
    else if(max == g) return ColorE::GREEN;
    else if (max == b) return ColorE::BLUE;
}

int Pixel::maxColorValue() {
    const int r = this->pixelColor.red;
    const int g = this->pixelColor.green;
    const int b = this->pixelColor.blue;

    int max = (r<g)?g:r;
    return ((b)?b:max);
}

int Pixel::averageColorValue() {
    return (this->pixelColor.red + this->pixelColor.green + this->pixelColor.blue) / 3;
}