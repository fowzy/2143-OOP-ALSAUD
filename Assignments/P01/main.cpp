#include <SFML/Graphics.hpp>
#include "Player.h"
int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Fowzy Alsaud - Simple Game");
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    sf::Vector2u TextureSize; //Added to store texture size.
    sf::Vector2u WindowSize;  //Added to store window size.

    // Create a ball
    Player player1;
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

        float ScaleX = (float)WindowSize.x / TextureSize.x;
        float ScaleY = (float)WindowSize.y / TextureSize.y; //Calculate scale.

        background.setTexture(BackgroundTexture);
        background.setScale(ScaleX, ScaleY); //Set scale.
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
        window.draw(background);
        player1.sprites(window);
        player1.moves();
        window.display();
    }
    return 0;
}
