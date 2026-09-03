#include "Processo.hpp"
#include <string>
#include <iostream>


Processo::Processo(int id, std::string nome, int prioridade){
    _id = id;
    _nome = nome;
    _prioridade = prioridade;
}

int Processo::getID(){
    return _id;
}

int Processo::getPrioridade(){
    return _prioridade;
}

std::string Processo::getNome(){
    return _nome;
}

double Processo::tempo_reservado_processo(){
    if(_prioridade == 2){
        return 3.0;
    }
    else if (_prioridade == 1){
        return 1.5;
    }
    else{
        return 0.5;
    }
}

void Processo::imprimir_dados(){
    if(_prioridade == 0){
        std::cout << _id << "\t" << _nome << "\t" << "BAIXA" << std::endl;
    }
    else if(_prioridade == 1){
        std::cout << _id << "\t" << _nome << "\t" << "MEDIA" << std::endl;
    }
    else if(_prioridade == 2){
        std::cout << _id << "\t" << _nome << "\t" << "ALTA" << std::endl;
    }
    
}







