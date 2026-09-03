// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_controle.hpp"
#include "FilaProcessos.hpp"
#include "Processo.hpp"

#include <string>
#include <iostream>

int main() {
    FilaProcessos fila;

    std::string input = {};

    while(std::cin >> input){
        if(input == "a"){
            std::string nome;
            int prioridade;
            std::cin >> nome >> prioridade;
            fila.adicionar_processo(nome,prioridade);
        }

        if(input == "r"){
            fila.remover_processo_maior_prioridade();
        }

        if(input == "i"){
            int id;
            std::cin >> id;
            fila.remover_processo_por_id(id);
        }

        if(input == "p"){
            fila.imprimir_fila();
        }

        if(input == "e"){
            int id;
            std::cin >> id;
            fila.estimativa_tempo_para_execucao(id);
        }

        if(input == "b"){
            avaliacao_basica();
        }


    }

    



    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //

    return 0;
}