#ifndef __testSFML__Rect__
#define __testSFML__Rect__
#include<SFML/Graphics.hpp>
#include "MyVector2D.h"
#include "Ball.h"

class Rect : public Ball
{
public:
    Rect(int window_width, int window_height);    
};

#endif /*  defined(__testSFML__Rect__)*/
