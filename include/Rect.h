#ifndef __testSFML__Rect__
#define __testSFML__Rect__
#include<SFML/Graphics.hpp>
#include "MyVector2D.h"

class Rect
{
public:
    sf::RectangleShape rect;
    MyVector2D vel;
    MyVector2D acc;

    Rect(int window_width, int window_height);

    void draw(sf::RenderWindow* window);
    void draw(sf::RenderWindow& window);
    void move(int window_width, int window_height);
};

#endif /*  defined(__testSFML__Rect__)*/
