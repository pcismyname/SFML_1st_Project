#include <SFML/Graphics.hpp>
#include <time.h>
#include "MyVector2D.h"

#include "Rect.h"

Rect::Rect(int window_width,int window_height)
{
    vel.x =rand()%10-5;
    vel.y = rand()%10-5;
    acc.x = 0;
    acc.y = 0;
    rect.setPosition( rand()%window_width, rand()%window_height);
    sf::Vector2f size((rand()%155), (rand()%155));
    rect.setSize(size);

    sf::Color color;
    color.r = rand()%255;
    color.g = rand()%255;
    color.b = rand()%255;
    rect.setFillColor(color);
}

void Rect::draw(sf::RenderWindow* window)
{
    window->draw(this->rect);
}

void Rect::draw(sf::RenderWindow& window)
{
    window.draw(this->rect);
}

void Rect::move(int window_width,int window_height)
{
    sf::Vector2f p = rect.getPosition();
    MyVector2D pos(p.x,p.y);
    vel = vel.add(acc);
    pos = pos + vel ;

    if(pos.x + rect.getSize().x > window_width)
    {
        pos.x = window_width -  rect.getSize().x;
        vel.x *= -1;

    }

     if(pos.y + rect.getSize().y > window_height)
    {
        pos.y = window_height -  rect.getSize().y;
        vel.y *= -1;

    }

    if (pos.x<0)
    {
        pos.x =0;
        vel.x *= -1;
    }

    if(pos.y<0)
    {
        pos.y =0;
        vel.y *= -1;
    }

    sf::Vector2f pos_now(pos.x,pos.y);
    rect.setPosition(pos_now);
}
