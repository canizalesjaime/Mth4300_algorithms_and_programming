#include <iostream>
#include "Rectangle.h"

int main() 
{
    Rectangle rect(10.0, 5.0);  // Create a Rectangle object with width 5.0 and height 3.0

    std::cout << "Area: " << rect.getArea() << std::endl;
    std::cout << "Perimeter: " << rect.getPerimeter() << std::endl;
    std::cout << rect;

    return 0;
}