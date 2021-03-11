//  P01             : Game (Ball and Debris)
//  Author          :   Fowzy Alsaud
//  OOP 2143        : 2021
//  Professor       : Dr. Griffen
//                             [ Classes ]
//  Player          : make a new player object
//  Debris          : make an debris's object and control it
//  Scoring         : this will give the user the result
//  Text            : control the text on the screen : font, size, location

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include "Player.h"
#include "Debris.h"
#include "Scoring.h"
#include "Text.h"
//#include "Game.h"

int main()
{
    //Game start;
    //Game();
    // std::vector<Debris> multipleDebris;
    // multipleDebris debris2;
    // multipleDebris.push_back(debris2());

    sf::RenderWindow window(sf::VideoMode(1500, 750), "Fowzy Alsaud - Simple Game");
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    sf::Vector2u TextureSize; //Added to store texture size.
    sf::Vector2u WindowSize;  //Added to store window size.
    sf::Texture texture;

    // Create a ball
    Player player1;
    // Create a debris

    Debris debris1(sf::IntRect(200, 100, 200, 100), sf::Color::Blue, {1000, 300}, {3,3});
    Debris debris2;
    // Debris debris3;
    // Debris debris4;
    // Debris debris5;
    std::vector<Debris> vecDebris;
    vecDebris.push_back(debris1);
    vecDebris.push_back(debris2);
    // Create a scoring object
    Scoring score;
    // Create a text object
    Text scoreOnScreen;
    //slow down speed
    window.setFramerateLimit(60);
    // Main Loop

    if (!BackgroundTexture.loadFromFile("assets/images/background.gif"))
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
    scoreOnScreen.setFont(); // Calling this function so we prepare and check the font otherwise text will not appear on the screen

    while (window.isOpen())
    {
        sf::Event evnt;

        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            { // event to close
            // "close requested" event: close the window
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed: // Event: When a key is pressed
                int y = 0;
                // int playerPosition = player1.getPosition(); // object position
                // int windowPosition = window.getSize().y; // size of my window (y)
                // if (playerPosition > 0 || !playerPosition > windowPosition) // if the position of player1 n
                // {
                if (evnt.key.code >= sf::Keyboard::Down) // when user press down arrow key
                {                                        // then the user will move down
                    player1.moves(y + 10);               // if t
                }
                else if (evnt.key.code >= sf::Keyboard::Up) // when user press up arrow key
                {                                           // then the user will move up
                    player1.moves(y - 10);
                }
            }
            break;
            // }
        }
        // If statemenet responsible to detect if there is any collision occurred
        if (debris1.getSprite().getGlobalBounds().intersects(player1.getSprite().getGlobalBounds()))
        {
            std::cout << "Collision occurred." << std::endl;
            score.lossPoint();
            std::cout << "Your new score is: " << score.getScore() << std::endl;
        } /*
        else {
            score.gainPoint();
        }*/
        window.clear();
        window.draw(background);          // space background
        window.draw(player1.getSprite()); // draw the player object on the screen
        for (int i = 0; i < vecDebris.size(); i++)
        {
            window.draw(vecDebris[i].getSprite());
            vecDebris[i].moves();
        }
        // window.draw(debris1.getSprite()); // draw the debris object on the screen
        // window.draw(debris2.getSprite()); // draw the debris object on the screen
        window.draw(scoreOnScreen.getText());
        // debris1.moves();  // moving the debris toward the player
        window.display(); // displaying my window
    }

    return 0;
}
