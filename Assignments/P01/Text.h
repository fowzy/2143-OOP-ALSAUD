//  Text Class responsible for:
//  Score gets displayed somewhere on the screen (one of the corners).
// Font, Location, Color, and Size should be configurable
class Text
{
private:
    //Default text var.
    sf::Text text;
    sf::Font font;
    // Location (Configurable) ex: (x,y)
    sf::Vector2f location;
    // Font (Configurable)
    std::string _changeFont;
    // Color (Configurable)
    sf::Color color;
    // Size (Configurable)
    int size;
public:
    Text()
    { //Default Constructor
        text;
        font;
        location = {10, 10};
        size = 50;
        color = sf::Color::White;
    }
    Text(int _size, sf::Color _color)
    { //Overloaded Constructor (Size, Font, Color, Location)
        //locate = _locate;
        //changeFont = __changeFont;
        color = _color;
        size = _size;
    }

    void setFont() // this function will set and check the existing of that font before it even print it out on the screen 
    {
        sf::Font setFont;
        if (!font.loadFromFile("assets/fonts/default.ttf")) // if not the file exist
        {
            std::cout << "Error loading file" << std::endl; // cout and error and pause the program

            system("pause");
        }
        text.setFont(font); // otherwise set the font ready for us
    }

    sf::Text getText() // our print function to print out and the score and configure the text on the screen
    {
        Scoring score;
        text.setFont(font); // control the font
        text.setString(score.PointtoString()); // print out the string
        text.setCharacterSize(size); // control the size
        text.setFillColor(color); // control the color
        text.setStyle(sf::Text::Style::Bold); //control the style
        text.setOutlineColor(sf::Color::Red); // control the outer line color
        text.setOutlineThickness(1); // control the thinkness of that outer line color
        text.setPosition(location.x, location.y); // location on the screen
        return text;
    }
};
