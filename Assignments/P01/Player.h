
#include <iostream>
class Player
{
private:
    //SIZE = 50 // configurable
    int size = 50;

    // COLOR: Green // configurable
    sf::Color color = sf::Color::Green;

    // LOCATIONS // configurable
    sf::Vector2f pos{0, 200};

    // CONTROL THE SPEED / vector for velocity
    sf::Vector2f vel{5, 5};

public:
    // this funx will move the ball one way in one direction
    void moves()
    {
        pos.x += vel.x; // Move one direction
        if (pos.x > 900 || pos.x < 0)
            vel.x = -vel.x; //boundary or to bounce back and don't go out of the view
        // pos.y += vel.y;
    }

    void events()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            pos.x = -2;
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) 
        {
            pos.x = 2;
        } 
        else 
        {
            pos.x = 0;
        } 
    }

    // int events(int x, int y)
    // { //get strike of the keyboard and move the ball
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up){
    //         pos.x = -2;
    //     }
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down){
    //         pos.x = 2;
    //     }
    //     else{
    //         pos.x = 0;
    //     }
    // }

    // draw ball to the window using position vector
    void sprites(sf::RenderWindow &window)
    {
        sf::CircleShape circle(size);     // shape (Circle) and size of the shape (50)
        circle.setPosition(pos.x, pos.y); // LOCATION: position (x and y) in another word is the location of the ball on the screen
        circle.setFillColor(color);       // COLOR: color the circle/ball
        window.draw(circle);              // shape on screen/ this thing will draw it on the screen for you
    }
};