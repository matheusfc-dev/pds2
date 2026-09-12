#ifndef JOGADOR_HPP
#define JOGADOR_HPP


#include <string>
#include <iostream>

class Jogador{
    public:
        std::string _nome;
        char _simbolo;

        Jogador(std::string nome, char simbolo);
        std::string getNome() const;
        char getSimbolo() const;


};

#endif