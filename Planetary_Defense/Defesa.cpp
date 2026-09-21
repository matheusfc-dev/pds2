#include "Defesa.hpp"
#include <iostream>

Defesa::Defesa(int id,double energia) : _id(id), _energia(energia) {}

void Defesa::_consumirEnergia(double qtd){
    _energia = _energia - qtd;
    if(_energia < 0.0){
        _energia = 0.0;
    }
}

double Defesa::_getEnergia(){
    return _energia;
}

Defesa::~Defesa(){
    std::cout << "Defesa " << _id << " desativada." << std::endl;
}