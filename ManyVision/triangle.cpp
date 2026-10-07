#include "triangle.hpp"
#include <cmath>

Triangle::Triangle(double s1, double s2, double s3){
    _a = s1;
    _b = s2;
    _c = s3;
}
std::string Triangle::name() const{
    return "Triangulo";
}

double Triangle::area() const{
    double s = (_a + _b + _c) / 2.0;
    return std::sqrt(s * (s - _a) * (s - _b) * (s - _c));

}