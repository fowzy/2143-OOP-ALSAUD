//  Player Class responsible for:
//  Player should be circle shape
//  Size, color and starting location should be random
//  Player has two movement up and down

class Player
{
private:
    //Size of the object (configurable)
    int size;
    // Color(configurable) using RGB code (0,0,0)
    sf::Color color;
    // Location (configurable) ex: (x,y)
    sf::Vector2f pos;
    // Velocity and responsible for speed of the object (in not configurable) ex: (5,5)
    sf::Vector2f vel;
    // how much are moving up and down variable
    int moveUpandDown;

public:
    //Default Constructor
    Player()
    {
        size = 50;
        color = sf::Color::Green;
        pos = {750, 325};
        vel = {10, 10};
        moveUpandDown = 10;
    }
    //Overloaded Constructor (Size, Color, Location)
    Player(int _size, sf::Color _color, sf::Vector2f _pos, sf::Vector2f _vel)
    {
        size = _size;
        color = _color;
        pos = _pos;
    }

    void moves(int y)
    {
        pos.y += y;
    }

    sf::CircleShape getSprite();

    int getPosition();
};

int Player::getPosition()
{
    return pos.y;
}

sf::CircleShape Player::getSprite()
{
    sf::CircleShape circle;
    circle.setRadius(size);             // shape (Circle) and size of the shape (50)
    circle.setPosition(pos.x, pos.y); // LOCATION: position (x and y) in another word is the location of the ball on the screen
    circle.setFillColor(color);       // COLOR: color the circle/ball
    return circle;
}