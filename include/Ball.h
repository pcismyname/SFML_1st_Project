#ifndef BALL_H
#define BALL_H

#include<SFML/Graphics.hpp>
#include "MyVector2D.h"

class Ball
{
public:
    sf::CircleShape circle;
    MyVector2D vel;
    MyVector2D acc;

    Ball(int window_width,int window_height);

    void draw(sf::RenderWindow * window);
    void draw(sf::RenderWindow& window);
    void move(int window_width,int window_height);
};
#endif // BALL_H
