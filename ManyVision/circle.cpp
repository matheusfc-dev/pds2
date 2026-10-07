#include "circle.hpp"
#include <cmath>

Circle::Circle(double radius){
    _radius = radius;
}

std::string Circle::name() const{

    return "Circulo";
}

double Circle::area() const{

    return std::acos(-1.0) * (_radius*_radius);
}