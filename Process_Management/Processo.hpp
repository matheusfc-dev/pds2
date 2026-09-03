#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <string>

struct Processo{
    int _id;
    int _prioridade;
    std::string _nome;
    Processo* next = nullptr;

    int getID();
    int getPrioridade();
    std::string getNome();

    Processo(int id, std::string nome, int prioridade);

    double tempo_reservado_processo();

    void imprimir_dados();


};




#endif