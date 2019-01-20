#ifndef PIXEL_H
#define PIXEL_H

enum ColorE {
    RED,
    GREEN,
    BLUE
};

struct Color {
    int red=0;
    int green=0;
    int blue=0;
};

class Pixel {
    private:
        Color pixelColor;

    public:
        Pixel();
        Pixel(int averageValue);
        Pixel(int r, int g, int b);
        ~Pixel();

        static Pixel randomPixel();

        Color grayScale(); // return a new pixel in gray scale copy of this
        int maxColorValue();
        ColorE maxColorType();
        int averageColorValue();
        Color getColor();
        string getColorString();
        void setColor(int value);
        void setColor(ColorE, int value);
        void setColor(int r, int g, int b);
        void setColor(Color c);
};

/* Some work to be done later
string& operator << (string& s, Pixel p);
ostream& operator << (std::ostream& os, Pixel p);
*/

#endif // !PIXEL_H