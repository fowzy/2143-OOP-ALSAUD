//  P01      :   Game
//  Author   :   Fowzy Alsaud
//  OOP 2143  - 2021
//  Dr. Griffen

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Debris.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Fowzy Alsaud - Simple Game");
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    sf::Vector2u TextureSize; //Added to store texture size.
    sf::Vector2u WindowSize;  //Added to store window size.

    // Create a ball
    Player player1;
    // Create a debris
    Debris debris1;
    //slow down speed
    window.setFramerateLimit(60);
    // Main Loop

    if (!BackgroundTexture.loadFromFile("space2.gif"))
    {
        return -1;
    }
    else
    {
        TextureSize = BackgroundTexture.getSize(); //Get size of texture.
        WindowSize = window.getSize();             //Get size of window.
        // configure the size of the backgound image
        float ScaleX = (float)WindowSize.x / TextureSize.x;
        float ScaleY = (float)WindowSize.y / TextureSize.y; //Calculate scale.

        background.setTexture(BackgroundTexture);
        background.setScale(ScaleX, ScaleY); //Set scale. to scale our background image
    }

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            // "close requested" event: close the window
            if (evnt.type == evnt.Closed)
                window.close();
        }
        // window.clear(sf::Color::Black); // ball is white so make backgnd black
        window.draw(background); // background 
        debris1.sprites(window);
        player1.sprites(window); // the shape
        player1.moves(); // moving
        // player1.events(changeX, changeY); // capture the strike of up and down arrow keys to move the ball
        window.display(); // displaying
    }
return 0;
}