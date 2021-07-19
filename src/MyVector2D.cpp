#include "MyVector2D.h"
#include<cmath>

MyVector2D::MyVector2D() :x(0),y(1)
{
}

MyVector2D::MyVector2D(double xx,double yy):x(xx), y(yy)
{

}

MyVector2D MyVector2D::add(MyVector2D v)
{
    MyVector2D result(v.x + x, v.y+y);
    return result;

}

MyVector2D MyVector2D::sub(MyVector2D v)
{
    MyVector2D result(x-v.x,y-v.y);
    return result;
}

MyVector2D MyVector2D::mul(double m)
{
    MyVector2D result( x*m, y*m);
    return result;

}

double MyVector2D::dot(MyVector2D v)
{
    double m = x*v.x + y*v.x;
    return m;
}

double MyVector2D::size()
{
    double m = sqrt(x*x + y*y);
    return m;
}

MyVector2D MyVector2D::unit()
{
    double s = size();
    MyVector2D result (x/s, y/s);
    return result;
}

MyVector2D MyVector2D::operator+(MyVector2D v)
{
    return add(v);
}

MyVector2D MyVector2D::operator-(MyVector2D v)
{
    return sub(v);
}

MyVector2D MyVector2D::operator*(double m)
{
    return mul(m);
}

double MyVector2D::operator^(MyVector2D v)
{
    return dot(v);
}



