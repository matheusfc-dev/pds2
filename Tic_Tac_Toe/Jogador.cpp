#include "Jogador.hpp"


Jogador::Jogador(std::string nome, char simbolo){
    _nome = nome;
    _simbolo = simbolo;
}


std::string Jogador::getNome() const{
    return this->_nome;
}

char Jogador::getSimbolo() const{
    return this->_simbolo;
}
