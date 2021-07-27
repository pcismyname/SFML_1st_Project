#ifndef STAR_H
#define STAR_H
#include<SFML/Graphics.hpp>
#include "MyVector2D.h"
class Star
{
public:
    sf::ConvexShape star[5];
    MyVector2D vel;
    MyVector2D acc;
    int N;
    int size;

    Star(int window_width,int window_height);

    void draw(sf::RenderWindow* window);
    void draw(sf::RenderWindow& window);
    void move(int window_width,int window_height);


};

#endif
