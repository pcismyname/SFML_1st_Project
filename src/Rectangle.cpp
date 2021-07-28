
#include "Rect.h"

Rect::Rect(int window_width,int window_height) : Ball( window_width, window_height)
{
    shape = new sf::RectangleShape();

    shape->setPosition(rand()%window_width, rand()%window_height);
    sf::Vector2f size((rand()%155),(rand()%155));
    ((sf::RectangleShape*)shape)->setSize(size);


    sf::Color color;
    color.r = rand()%255;
    color.g = rand()%255;
    color.b = rand()%255;
    shape->setFillColor(color);
}


