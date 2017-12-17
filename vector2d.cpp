#include "vector2d.h"

Vector2d::Vector2d(double x, double y){
    p[0] = x;
    p[1] = y;
}

double * Vector2d:: getPoint(){
    return p;
}

double Vector2d::getX(){
    return p[0];
}

double Vector2d::getY(){
    return p[1];
}

Vector2d Vector2d::operator + ( Vector2d& c) {
    double x = getX() + c.getX();
    double y = getY() + c.getY();
    return Vector2d(x, y);
}

Vector2d Vector2d::operator - ( Vector2d& c) {
    double x = c.getX() - getX();
    double y = c.getY() - getY();
    return Vector2d(x, y);
}

double Vector2d::operator*(Vector2d& c){
    return getX()*c.getX() + getY() * c.getY();
}

Vector2d Vector2d::operator*(double c){
    return Vector2d(getX() * c, getY() * c);
}

Vector2d Vector2d::operator/(double c){
    return Vector2d(getX() / c, getY() / c);
}


double Vector2d::SlopeWithRespectTo(Vector2d& c){
    return (c.getY() - getY()) / (c.getX() - getX());
}

Vector2d::printP(){
    std::cout << "X:" << getX() << "\tY:" << getY() << std::endl;
}

double Vector2d::Distance(Vector2d& c){
    return sqrt( pow(c.getX() - getX(), 2) + pow(c.getY() - getY(), 2) );
}

double Vector2d::GetLength(){
    return sqrt( getX() * getX() + getY() * getY());
}