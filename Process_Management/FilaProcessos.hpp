#ifndef FILAPROCESSOS_HPP
#define FILAPROCESSOS_HPP

#include "Processo.hpp"
#include <string>

struct FilaProcessos{

    Processo* head = nullptr;
    Processo* tail = nullptr;
    int contador = 1;


    void adicionar_processo(std::string nome, int prioridade);

    Processo* remover_processo_maior_prioridade();

    Processo* remover_processo_por_id(int id);

    void estimativa_tempo_para_execucao(int id);

    void imprimir_fila();
};


#endif