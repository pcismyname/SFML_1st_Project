#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>

#include "MyVector2D.h"

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

    sf::CircleShape circle[10];
    MyVector2D vel[10];
    MyVector2D acc[10];

    for (int i = 0; i < 10; i++)
    {
        vel[i].x = rand() % 10 - 5;
        vel[i].y = rand() % 10 - 5;
        acc[i].x = 0;
        acc[i].y = 0.4;
        circle[i].setPosition(rand() % window_size2.x, rand() % window_size2.y);
        circle[i].setRadius(rand() % 115);
        sf::Color color;
        color.r = rand() % 225;
        color.g = rand() % 225;
        color.b = rand() % 225;
        color.a = rand() % 155 + 100;
        circle[i].setFillColor(color);
    }

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

        ///////////////

        sf::Vector2u window_size = window.getSize();
        for (int i = 0; i < 10; i++)
        {
            sf::Vector2f p = circle[i].getPosition();
            MyVector2D pos(p.x, p.y);
            vel[i] = vel[i].add(acc[i]);
            pos = pos + vel[i];

            if (pos.x + 2 * circle[i].getRadius() > window_size.x)
            {
                pos.x = window_size.x - 2 * circle[i].getRadius();
                vel[i].x *= -1;
            }

            if (pos.y + 2 * circle[i].getRadius() > window_size.y)
            {
                pos.y = window_size.y - 2 * circle[i].getRadius();
                vel[i].y *= -1;
            }

            if (pos.x < 0)
            {
                pos.x = 0;
                vel[i].x *= -1;
            }

            if (pos.y < 0)
            {
                pos.y = 0;
                vel[i].y *= -1;
            }

            sf::Vector2f pos_now(pos.x, pos.y);
            circle[i].setPosition(pos_now);
            window.draw(circle[i]);
        }
        window.display();
    }
    return EXIT_SUCCESS;
}
