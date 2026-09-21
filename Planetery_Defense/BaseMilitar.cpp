#include "BaseMilitar.hpp"

#include <iostream>
#include <iomanip>

void BaseMilitar::adicionarDefesa(Defesa* d){
    _defesas[_qtdAtual] = d;
    _qtdAtual ++;
}

void BaseMilitar::defender(double &saudeInimigo){
    double danoTotal = 0.0;

    for(int i = 0; i < _qtdAtual; i++){
        _defesas[i]->atacar(danoTotal);
    }

    saudeInimigo -= danoTotal;
    std::cout << std::fixed << std::setprecision(2) << "Saude Inimigo: " << saudeInimigo << std::endl;
}

BaseMilitar::~BaseMilitar(){
    for(int k = 0; k < _qtdAtual; k++){
        delete _defesas[k];
    }
}