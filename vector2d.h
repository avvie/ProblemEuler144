#ifndef Vector2d_H
#define Vector2d_H
#include <iostream>
#include <cmath>

class Vector2d{
    public:
        Vector2d(double x, double y);
        double* getPoint();
        double getX();
        double getY();
        Vector2d operator+ (Vector2d& c) ;
        Vector2d operator- (Vector2d& c) ;
        double SlopeWithRespectTo(Vector2d& c);
        double Distance(Vector2d& c);
        Vector2d Direction(Vector2d& c);
        double operator*(Vector2d& c);
        double GetLength();
        Vector2d operator*(double c);
        Vector2d operator/(double c);
        printP();

    private:
        double p [2];

};

#endif