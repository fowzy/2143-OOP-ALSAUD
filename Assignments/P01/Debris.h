//  Debris Class responsible for:
//  Debris should be rectangle shape
//  Size , color, and starting location should be configurable
//  Debris should move from right to left at random Y location
//  Size should be random and should be set between min  and max
//  Frequency and speed should be slowly increase over time.
class Debris
{
private:
    //Size of our Debris object (configurable)
    sf::IntRect size;
    // Color (configurable)
    sf::Color color;
    // Location (configurable)
    sf::Vector2f pos;
    // Velocity and controlling the speed (in not configurable)
    sf::Vector2f vel;

public:
    //Default Constructor
    Debris()
    {
        size = sf::IntRect(200, 100, 200, 100);
        color = sf::Color::Red;
        pos = {1400, 325};
        vel = {6, 6};
    }
    //Overloaded Constructor (Size, Color, Location)
    Debris(sf::IntRect _size, sf::Color _color, sf::Vector2f _pos, sf::Vector2f _vel)
    {
        size = _size;
        color = _color;
        pos = _pos;
        vel = _vel;
    }

    // Function responsible for moving toward the player
    void moves()
    { // we we're going to move the object from the right to the left side
        pos.x -= vel.x;
    }
    // getSprite: is simple function to create a rectangle shape object and is going to be our Debris
    sf::Sprite getSprite();
};

sf::Sprite Debris::getSprite()
{
    sf::Sprite debris;
    sf::Texture texture;
    debris.setTexture(texture);       // texture of our object
    debris.setTextureRect(size);      // Size of object
    debris.setPosition(pos.x, pos.y); // Location of our object
    debris.setColor(color);           // Color of object
    return debris;
}