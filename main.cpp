#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Rect.h"
#include "MyVector2D.h"
#include "Ball.h"
#include "Star.h"
#define N 10


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "shape everywhere !!!!!!!!!", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::ContextSettings setting = window.getSettings();
    setting.antialiasingLevel = 1000;

    srand(time(NULL));
    sf::Vector2u window_size2 = window.getSize();

    ///////////////////////////////////////////

    Ball **ball = new Ball *[30];
    for (int i = 0; i < 10; i++)
    {
        ball[i] = new Ball(window_size2.x, window_size2.y);
    }

   
    for (int i = 10; i < 20; i++)
    {
        ball[i] = new Rect(window_size2.x, window_size2.y);
    }

   
    for (int i = 20; i < 30; i++)
    {
        ball[i] = new Star(window_size2.x, window_size2.y);
    }

    ///////////////////////////////////////////
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }

        window.clear();

        ///////////////////////////////////////////////////

        sf::Vector2u window_size = window.getSize();

        for (int i = 0; i < N*3; i++)
        {
            ball[i]->move(window_size.x, window_size.y);
        }

        for (int i = 0; i < N*3; i++)
        {
            ball[i]->draw(&window);
        }

       

        window.display();
    }

    ///////////////////////////////////////////////////////////

    for (int i = 0; i < 30; i++)
    {
        delete ball[i];
    }

    delete [] ball;

  

    return EXIT_SUCCESS;
}
