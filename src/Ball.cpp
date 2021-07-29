#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball(int window_width, int window_height)
{
    pos.x = rand() % window_width;
    pos.y = rand() % window_height;
    vel.x = rand() % 10 - 5;
    vel.y = rand() % 10 - 5;
    acc.x = 0;
    acc.y = 0; 
    
    size = rand() % 120;

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;

    N = 1;
    shape = new sf::Shape *[N];
    shape[0] = new sf::CircleShape();
    ((sf::CircleShape *)shape[0])->setRadius(size / 2);
    shape[0]->setFillColor(color);
    shape[0]->setPosition(pos.x, pos.y);
}

Ball::~Ball()
{
    for (int i = 0; i < N; i++)
    {
        delete shape[i];
    }
    delete[] shape;
}

void Ball::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < N; i++)
    {
        window.draw(*(this->shape[i]));
    }
}

void Ball::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < N; i++)
    {
        window->draw(*(this->shape[i]));
    }
}

void Ball::move(int window_width, int window_height)
{

    vel = vel.add(acc); //vel[i] + acc[i]
    pos = pos + vel;
    bool isCollision = false;

    if (pos.x + size > window_width)
    {
        pos.x = window_width - size;
        vel.x *= -1;
        isCollision = true;
    }

    if (pos.y + size > window_height)
    {
        pos.y = window_height - size;
        vel.y *= -1;
        isCollision = true;
    }

    if (pos.x < 0)
    {
        pos.x = 0;
        vel.x *= -1;
        isCollision = true;
    }

    if (pos.y < 0)
    {
        pos.y = 0;
        vel.y *= -1;
        isCollision = true;
    }

    sf::Vector2f pos_now(pos.x, pos.y);
    for (int i = 0; i < N; i++)
    {
        shape[i]->setPosition(pos_now);
    }

    if (isCollision)
    {
        sf::Color color;
        color.r = rand() % 255;
        color.g = rand() % 255;
        color.b = rand() % 255;
        shape[0]->setFillColor(color);
        for (int i = 0; i < N; i++)
        {
            shape[i]->setFillColor(color);
        }
    }
}
