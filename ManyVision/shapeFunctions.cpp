#include "shapeFunctions.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

void ShapeFunctions::printShapes(const std::vector<Shape*>& shapes){
    for(int i = 0; i < shapes.size(); i ++){
        std::cout << std::fixed << std::setprecision(2) << *shapes[i] << std::endl;
    }
}

double ShapeFunctions::totalArea(const std::vector<Shape*>& shapes){
    double soma = 0.0;
    for(int i = 0; i < shapes.size(); i++){
        soma += shapes[i]->area();
    }
    return soma;
}

std::vector<Shape*> ShapeFunctions::getShapesWithAreaGreaterThan(const std::vector<Shape*>& shapes, double minArea){
    std::vector<Shape*> v;
    for(int i = 0; i < shapes.size(); i++){
        if(shapes[i]->area() > minArea){
            v.push_back(shapes[i]);
        }
    }
    return v;
}

bool compararArea(Shape* a, Shape* b){
    return a->area() < b->area();
    }

void ShapeFunctions::sortShapesByArea(std::vector<Shape*>& shapes){

    std::sort(shapes.begin(),shapes.end(),compararArea);
}

std::map<std::string, int> ShapeFunctions::countShapesByName(const std::vector<Shape*>& shapes){
    std::map<std::string, int> retorno;
    for(int i = 0; i < shapes.size(); i++){
        retorno[shapes[i]->name()]++;
    }
    return retorno;
}

std::set<double> ShapeFunctions::uniqueAreas(const std::vector<Shape*>& shapes){
    std::set<double> areas;

    for(int i = 0; i < shapes.size(); i++){
        areas.insert(shapes[i]->area());
    }
    return areas;
}

void ShapeFunctions::verificarTraversable(const std::vector<Shape*>& shapes, double area_ambiente, double tolerancia){
    double area_livre = area_ambiente - totalArea(shapes);
    if(area_livre > tolerancia){
        std::cout << "Ambiente trafegavel. Area livre: " <<  std::fixed << std::setprecision(2) << area_livre << std::endl;
    }
    else{
        std::cout << "Ambiente nao trafegavel. Area livre insuficiente: " << std::fixed << std::setprecision(2) << area_livre << std::endl;
    }
}