#include <iostream>
#include "vector2d.h"
#include <cmath>

typedef Vector2d Point;

int main()
{
  // count reflections
  unsigned int steps = 0;

  // initial ray
  Point from(0.0, 10.1);
  Point to  (1.4, -9.6);

  while (true)
  {
    // exit ellipse condition
    if (to.getX() >= -0.01 && to.getX() <= 0.01 && to.getY() > 10 - 0.1) 
      break;

    // find inward pointing normal
    Point normal = Point(-4 * to.getX(), -to.getY());
    // normalize vector length
    // normal.printP();
    double length = normal.GetLength();
    normal = normal / length;
    std::cout << "normal: ";
    normal.printP();
    // current direction of the ray
    Vector2d direction = from - to;
    std::cout << "direction: ";
    direction.printP();
    // degenerated case
    if (direction.getX() == 0)
    {
      steps++; // same as steps = 1 in this case
      break;
    }

    // reflect ray at intersection considering the normal
    double x = direction.getX() - (2 * (direction * normal) * normal.getX());
    double y = direction.getY() - (2 * (direction * normal) * normal.getY());
    // std::cout << "x: " << x << " y:" << y <<  std::endl;
    Vector2d reflect(x,
                     y);
    std::cout << "reflect: " ; 
    reflect.printP();
    // slope of the reflected ray
    double slope = reflect.getY() / reflect.getX();
    std::cout << "slope: " << slope << std::endl;
    // previous endpoint becomes the start point of the next iteration
    from = Point(to.getX(), to.getY());
    std::cout << "from: ";
    from.printP();
    
    // find next intersection
    x = (4*from.getX() - slope*slope*from.getX() + 2*slope*from.getY()) / (-4 - slope*slope); 
    y = slope * (x - from.getX()) + from.getY();
    
    
    to = Point(x, y);

    // count iterations
    steps++;
    std::cout << "to: ";
    to.printP();
    std::cout <<  std::endl<< std::endl;
  }

  // display result
  std::cout << steps << std::endl;
  return 0;
}
