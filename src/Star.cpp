#include "Star.h"
#include <cmath>

#define PI 3.141592653589793
#define TWO_PI 2 * 3.141592653589793

Star::Star(int window_width, int window_height) : Ball(window_width, window_height)
{
    N = 5;
    shape = new sf::Shape *[N];

    for (int i = 0; i < N; i++)
    {
        shape[i] = new sf::ConvexShape;
        sf::ConvexShape *x_shape = ((sf::ConvexShape *)shape[i]);

        x_shape->setPointCount(4);
        x_shape->setPoint(0, sf::Vector2f(0, 0));

        double Angle_now = TWO_PI / N * i;
        double Angle_half_step = TWO_PI / N / 2.0;
        x_shape->setPoint(1, sf::Vector2f(size / 2 * cos(Angle_now - Angle_half_step), size / 2 * sin(Angle_now - Angle_half_step)));
        x_shape->setPoint(2, sf::Vector2f(size * cos(Angle_now), size * sin(Angle_now)));
        x_shape->setPoint(3, sf::Vector2f(size / 2 * cos(Angle_now + Angle_half_step), size / 2 * sin(Angle_now + Angle_half_step)));

        x_shape->setFillColor(color);

        x_shape->setPosition(rand() % window_width, rand() % window_height);
    }

}
