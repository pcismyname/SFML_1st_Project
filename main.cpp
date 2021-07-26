#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Rect.h"
#include "MyVector2D.h"
#include "Ball.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "ball ball ball", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::ContextSettings setting = window.getSettings();
    setting.antialiasingLevel = 1000;

    srand(time(NULL));
    sf::Vector2u window_size2 = window.getSize();

    ///////////////////////////////////////////

    Ball **ball = new Ball*[10];
    for (int i = 0; i < 10; i++)
    {
        ball[i] = new Ball(window_size2.x, window_size2.y);
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

        /////////////////////////////////////

        sf::Vector2u window_size = window.getSize();

        for (int i = 0; i < 10; i++)
        {
            ball[i]->move(window_size.x, window_size.y);
        }

        for (int i = 0; i < 10; i++)
        {
            ball[i]->draw(&window);
        }

          window.display();

    }
      for(int i=0;i<10;i++)
        {
            delete ball[i];
        }


    delete [] ball;
    return EXIT_SUCCESS;
}
