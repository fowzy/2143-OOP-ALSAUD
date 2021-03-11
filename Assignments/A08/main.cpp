#include <iostream>
#include <vector>
using namespace std;

/**
 * This class is a simple bare bones example showing use of a copy constructor
 * for the question on the exam.
 * 
 *
 * 
 *
 * 
 */


class NumContainer
{
    int *array; // int pointer (dynamic memory)
    int size;

public:
    NumContainer()
    {
        size = 100;
        array = new int[size];
    }
    NumContainer(int s)
    {
        size = s;
        array = new int[size];
    }
    NumContainer(const NumContainer &other)
    {
        size = other.size;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
    }
};

/**
 * This is an implementation of our single color rgb class. 
 * 
 */
class RgbColor
{
    int r; //int 0-255 red
    int g; //int 0-255 green
    int b; //int 0-255 blue
public:
    RgbColor();              // default constructor
    RgbColor(int);           // overloaded 1
    RgbColor(int, int, int); // overloaded 2

    void SetR(int); // setter red
    void SetG(int); // setter green
    void SetB(int); // setter blue

    int GetR(); // getter red
    int GetG(); // getter green
    int GetB(); // getter blue

    void GrayScale(); // averages colors

    // print to stdout
    friend ostream &operator<<(ostream &, const RgbColor &);

    // add (mix) two colors
    RgbColor operator+(const RgbColor &);
};

RgbColor RgbColor::operator+(const RgbColor &rhs)
{
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}

RgbColor::RgbColor()
{
    r = g = b = 0;
}

RgbColor::RgbColor(int color)
{
    r = g = b = color;
}

RgbColor::RgbColor(int _r, int _g, int _b)
{
    r = _r;
    g = _g;
    b = _b;
}

ostream &operator<<(ostream &os, const RgbColor &rhs)
{
    os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    return os;
}

class ColorPallette : public RgbColor //inherit from RgbColor
{                                     // Class ColorPallette will store colors only and we can using arrays or vectors and make sure we store them in dynamically allocated structure
public:
    ColorPallette()
    { // Default Constructor
        vecColor.push_back(RgbColor(0, 0, 0));
    }
    ColorPallette(RgbColor newColor)
    { // Overloaded Constructor
        vecColor.push_back(newColor);
    }

    // function to add new color to the vectors
    void addColor(RgbColor newColor)
    {
        vecColor.push_back(newColor);
    }
    //function to return the color in our vectors
    vector<RgbColor> getColor() 
    {
        return vecColor;
    }
    // create vector in my class
    // then use the color from RgbColor to ColorPallette

private:
    vector<RgbColor> vecColor;
};

int main()
{
    RgbColor Color1(255, 200, 11);
    RgbColor Color2(100, 14, 123);
    // create an object for color pallette, and add pass color1 to our pallette 
    ColorPallette ColorPal1(Color1);
    vector <RgbColor> a;
    RgbColor Color3 = Color1 + Color2;

    // add color 2 to our vector
    ColorPal1.addColor(Color2);
    a = ColorPal1.getColor();
    // read the vectors using for loop
    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << ' ' << endl;
}