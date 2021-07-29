#ifndef BALL_H
#define BALL_H

#include<SFML/Graphics.hpp>
#include "MyVector2D.h"

class Ball
{
public:
    sf::Shape** shape;
    int N;
    MyVector2D vel;
    MyVector2D acc;
    MyVector2D pos;
    int size;
    sf::Color color;
    Ball(int window_width,int window_height);
    ~Ball();
    void draw(sf::RenderWindow * window);
    void draw(sf::RenderWindow& window);
    void move(int window_width,int window_height);
};
#endif // BALL_H
