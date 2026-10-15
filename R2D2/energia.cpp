#include "energia.hpp"
#include <cmath>

Energia::Energia(int carga_inicial):carga_(carga_inicial){

}


int Energia::getCarga() const {
    if(carga_ < 0){
        return 0;
    }
    return carga_;

}

void Energia::consumir(int quantidade) {
    if(quantidade < 0){
        quantidade = 0;
    }
    carga_ -= quantidade;
    if(carga_ < 0){
        carga_ = 0;
    }
}