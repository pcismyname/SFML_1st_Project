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

    Ball **ball = new Ball *[N];
    for (int i = 0; i < N; i++)
    {
        ball[i] = new Ball(window_size2.x, window_size2.y);
    }

    Rect **rect = new Rect *[N];
    for (int i = 0; i < N; i++)
    {
        rect[i] = new Rect(window_size2.x, window_size2.y);
    }

    Star **star = new Star *[N];
    for (int i = 0; i < N; i++)
    {
        star[i] = new Star(window_size2.x, window_size2.y);
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

        for (int i = 0; i < N; i++)
        {
            ball[i]->move(window_size.x, window_size.y);
        }

        for (int i = 0; i < N; i++)
        {
            ball[i]->draw(&window);
        }

        for (int i = 0; i < N; i++)
        {
            rect[i]->move(window_size.x, window_size.y);
        }

        for (int i = 0; i < N; i++)
        {
            rect[i]->draw(&window);
        }

        for (int i = 0; i < N; i++)
        {
            star[i]->move(window_size.x, window_size.y);
        }

        for (int i = 0; i < N; i++)
        {
            star[i]->draw(&window);
        }

        window.display();
    }

    ///////////////////////////////////////////////////////////

    for (int i = 0; i < N; i++)
    {
        delete ball[i];
    }

    delete [] ball;

    for (int i = 0; i < N; i++)
    {
        delete rect[i];
    }

    delete [] rect;


    for (int i = 0; i < N; i++)
    {
        delete star[i];
    }

    delete [] star;

    return EXIT_SUCCESS;
}
