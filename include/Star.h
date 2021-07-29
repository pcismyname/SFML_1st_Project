#ifndef STAR_H
#define STAR_H
#include<SFML/Graphics.hpp>
#include "MyVector2D.h"
#include "Ball.h"
class Star : public Ball
{
public:
    Star(int window_width,int window_height);
};

#endif
