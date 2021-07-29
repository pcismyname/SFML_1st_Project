
#include "Rect.h"

Rect::Rect(int window_width, int window_height) : Ball(window_width, window_height)
{
    N = 1;
    shape = new sf::Shape*[N];
    shape[0] = new sf::RectangleShape();
    
    sf::Vector2f sizexx(this->size, this->size);
    ((sf::RectangleShape *)shape[0])->setSize(sizexx);

    shape[0]->setPosition(pos.x, pos.y);
    shape[0]->setFillColor(color);
}

void Rect::move(int window_width, int window_height)
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
