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

    srand(time(NULL));
    sf::Vector2u window_size2 = window.getSize();

    sf::ContextSettings setting = window.getSettings();
    setting.antialiasingLevel = 1000;

    ///////////////////////////////////////////

    Ball ball[10];
    for (int i = 0; i < 10; i++)
    {
        ball[i].vel.x = rand() % 10;
        ball[i].vel.y = rand() % 10;
        ball[i].acc.x = 0;
        ball[i].acc.y = 0;
        ball[i].circle.setPosition(rand() % window_size2.x, rand() % window_size2.y);
        ball[i].circle.setRadius(rand() % 155);

        sf::Color color;
        color.r = rand() % 255;
        color.g = rand() % 255;
        color.b = rand() % 255;
        ball[i].circle.setFillColor(color);
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
            ball[i].move(window_size.x, window_size.y);
        }

        for(int i =0; i< 10;i++)
        {
            ball[i].draw(&window);
        }


        window.display();
    }
    return EXIT_SUCCESS;
}
