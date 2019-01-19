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

Pixel::~Pixel() {

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

void Pixel::setColor(Color c) {
    this->pixelColor = c;
}

void Pixel::setColorRed(int value) {
    this->pixelColor.red = value;
}

void Pixel::setColorGreen(int value) {
    this->pixelColor.green = value;
}

void Pixel::setColorBlue(int value) {
    this->pixelColor.blue = value;
}

Color Pixel::grayScale() {
    int average = this->averageColorValue();
    Color c;
    c.red = average; c.green = average; c.blue = average;
    return c;
}

int Pixel::maxColorValue() {
    int max = (this->pixelColor.red<this->pixelColor.green)?this->pixelColor.green:this->pixelColor.red;
    return ((max<this->pixelColor.blue)?this->pixelColor.blue:max);
}

int Pixel::averageColorValue() {
    return (this->pixelColor.red + this->pixelColor.green + this->pixelColor.blue) / 3;
}