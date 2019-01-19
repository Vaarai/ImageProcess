#ifndef PIXEL_H
#define PIXEL_H

struct Color {
    int red;
    int green;
    int blue;
};

class Pixel {
    private:
        Color pixelColor;

    public:
        Pixel();
        Pixel(int averageValue);
        Pixel(int r, int g, int b);
        ~Pixel();

        Color grayScale(); // return a new pixel in gray scale copy of this
        int maxColorValue();
        int averageColorValue();
        Color getColor();
        void setColor(int value);
        void setColor(int r, int g, int b);
        void setColor(Color c);
        void setColorRed(int value);
        void setColorGreen(int value);
        void setColorBlue(int value);
};

#endif // !PIXEL_H