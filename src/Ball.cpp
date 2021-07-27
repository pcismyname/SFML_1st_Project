#include "Ball.h"
#include<SFML/Graphics.hpp>

Ball::Ball(int window_width,int window_height)
{
        vel.x = rand() % 10-5;
        vel.y = rand() % 10-5;
        acc.x = 0;
        acc.y = 0;
        circle.setPosition(rand() % window_width, rand() % window_height);
        circle.setRadius(rand() % 155);

        sf::Color color;
        color.r = rand() % 255;
        color.g = rand() % 255;
        color.b = rand() % 255;
        circle.setFillColor(color);
}



void Ball::draw(sf::RenderWindow& window)
{
    window.draw(this->circle);
}

void Ball::draw(sf::RenderWindow* window)
{
    window->draw(this->circle);
}

void Ball::move(int window_width, int window_height)
{
    sf::Vector2f p = circle.getPosition();
    MyVector2D pos(p.x,p.y);
    vel = vel.add(acc); //vel[i] + acc[i]
    pos = pos + vel;

    if(pos.x + 2*circle.getRadius() > window_width)
    {
        pos.x = window_width - 2* circle.getRadius();
        vel.x *= -1;
    }

    if(pos.y + 2*circle.getRadius() > window_height)
    {
        pos.y = window_height - 2* circle.getRadius();
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
    circle.setPosition(pos_now);
}
