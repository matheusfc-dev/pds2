#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height){
    _width = width;
    _height = height;
}

std::string Rectangle::name() const{
    return "Retangulo";
}

double Rectangle::area() const{
    return _width*_height;
}