#include "Ball.h"
#include<SFML/Graphics.hpp>

Ball::Ball(int window_width,int window_height)
{
        shape = new sf::CircleShape();
        vel.x = rand() % 10-5;
        vel.y = rand() % 10-5;
        acc.x = 0;
        acc.y = 0;
        shape->setPosition(rand() % window_width, rand() % window_height);
        size = rand()%200;
        ((sf::CircleShape*)shape)->setRadius(size/2);


        sf::Color color;
        color.r = rand() % 255;
        color.g = rand() % 255;
        color.b = rand() % 255;
        shape->setFillColor(color);
}



void Ball::draw(sf::RenderWindow& window)
{
    window.draw(*this->shape);
}

void Ball::draw(sf::RenderWindow* window)
{
    window->draw(*this->shape);
}

void Ball::move(int window_width, int window_height)
{
    sf::Vector2f p = shape->getPosition();
    MyVector2D pos(p.x,p.y);
    vel = vel.add(acc); //vel[i] + acc[i]
    pos = pos + vel;

    if(pos.x + size > window_width)
    {
        pos.x = window_width - size;
        vel.x *= -1;
    }

    if(pos.y + size > window_height)
    {
        pos.y = window_height - size;
        vel.y *= -1;
    }

    if(pos.x < 0)
    {
        pos.x = 0;
        vel.x *= -1;
    }

    if(pos.y < 0)
    {
        pos.y = 0;
        vel.y *= -1;
    }

    sf::Vector2f pos_now(pos.x,pos.y);
   shape->setPosition(pos_now);
}
