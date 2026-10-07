#include "shapeFunctions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

#include "iostream"
#include "iomanip"

int main(){
    std::vector<Shape*> shapes;
    std::string entrada;

    while(std::cin >> entrada){

        if(entrada == "CIRCLE"){
            double r;
            std::cin >> r;
            shapes.push_back(new Circle(r));
            

        }

        if(entrada == "RECT"){
            double w;
            double h;
            std::cin >> w >> h;
            shapes.push_back(new Rectangle(w,h));
            

        }

        if(entrada == "TRIANGLE"){
            double a;
            double b;
            double c;
            std::cin >> a >> b >> c;
            shapes.push_back(new Triangle(a,b,c));
            

        }

        if(entrada == "LIST"){
            ShapeFunctions::printShapes(shapes);
        }

        if(entrada == "TOTAL"){
            double soma = ShapeFunctions::totalArea(shapes);
            std::cout << "Total: " << std::fixed << std::setprecision(2) << soma << std::endl;
        }

        if(entrada == "SORT"){
            ShapeFunctions::sortShapesByArea(shapes);
            ShapeFunctions::printShapes(shapes);

        }

        if(entrada == "FILTER"){
            double min_area;
            std::cin >> min_area;
            ShapeFunctions::printShapes(ShapeFunctions::getShapesWithAreaGreaterThan(shapes,min_area));

        }

        if(entrada == "COUNT"){
            std::map<std::string, int> contagem = ShapeFunctions::countShapesByName(shapes);
            for (const auto& par : contagem) {
                std::cout << par.first << ": " << par.second << std::endl;
            }
        }

        if(entrada == "UNIQUE"){
            std::set<double> unicas;
            unicas = ShapeFunctions::uniqueAreas(shapes);
            for (const auto& n : unicas){
                std::cout << std::fixed << std::setprecision(2) << n << " ";
            }
        }

        if (entrada == "CLEAR") {
            for (Shape* shape : shapes) {
                delete shape;
            }

            shapes.clear();
        }

        if(entrada == "TRAVERSABLE"){
            double area_ambiente, tolerancia;
            std::cin >> area_ambiente >> tolerancia;
            ShapeFunctions::verificarTraversable(shapes, area_ambiente, tolerancia);
        }



    }





}