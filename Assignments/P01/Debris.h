
#include <iostream>
#include <SFML/Graphics.hpp>

class Debris
{
private:
    //SIZE = 50 // configurable
    // int size = 50;
    sf::Vector2f size = sf::Vector2f(100, 50);
    // COLOR: Green // configurable
    sf::Color color = sf::Color::Red;

    // LOCATIONS // configurable
    sf::Vector2f pos{500, 0};

    // CONTROL THE SPEED / vector for velocity
    sf::Vector2f vel{6, 6};

public:
    // this funx will move the ball one way in one direction
    void moves()
    {
        pos.y += vel.y; // Move one direction
        if (pos.y > 450 || pos.y < 0)
        vel.y = -vel.y; //boundary or to bounce back and don't go out of the view
        // pos.y += vel.y;
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
        sf::RectangleShape rectangle;
        rectangle.setSize(size);   // shape (Circle) and size of the shape (50)
        rectangle.setPosition(pos.x, pos.y); // LOCATION: position (x and y) in another word is the location of the ball on the screen
        rectangle.setOutlineColor(color);       // COLOR: color the circle/ball
        window.draw(rectangle);              // shape on screen/ this thing will draw it on the screen for you
    }
};