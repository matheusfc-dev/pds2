#include "Processo.hpp"
#include "FilaProcessos.hpp"

#include <string>
#include <iostream>
#include <iomanip>



void FilaProcessos::adicionar_processo(std::string nome, int prioridade){ 

    Processo* aux = new Processo(FilaProcessos::contador++,nome,prioridade);

    if(FilaProcessos::head == nullptr){
        FilaProcessos::head = aux;
        FilaProcessos::tail = aux;
    }
    else if(aux->_prioridade > head->_prioridade){
        aux->next = head;
        head = aux;
    }
    else{
        Processo* atual = head;

        while (atual->next != nullptr && atual->next->_prioridade >= aux->_prioridade) {
            atual = atual->next;
        }
        
        aux->next = atual->next;
        atual->next = aux;
        
        if (aux->next == nullptr) {
            tail = aux;
        }
    }
}

Processo* FilaProcessos::remover_processo_maior_prioridade(){
    if(head != nullptr){
        Processo* removido = head;
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        return removido;
    }

    return nullptr;

}

Processo* FilaProcessos::remover_processo_por_id(int id){

    if(head == nullptr){
        return nullptr;
    }

    if(head->_id == id){
        Processo* removido = head;
        head = head->next;

        if(head == nullptr){
            tail = nullptr;
        }

        return removido;
    }

    Processo* atual = head;

    while(atual->next != nullptr && atual->next->_id != id){
        atual = atual->next;
    }

    if(atual->next == nullptr){
        return nullptr;
    }

    Processo* removido = atual->next;
    atual->next = removido->next;

    if(atual->next == nullptr){
        tail = atual;
    }

    return removido;
    
}

void FilaProcessos::estimativa_tempo_para_execucao(int id){
    Processo* atual = head;
    double tempo = 0.0;

    while(atual != nullptr && atual->_id != id){
        tempo = tempo + atual->tempo_reservado_processo();
        atual = atual->next;   
    }

    //tempo = tempo + atual->tempo_reservado_processo();

    if(atual == nullptr){
        return;
    }

    std::cout << "Tempo estimado para execução do processo " << atual->_nome << " (id=" << atual->_id << ") eh " << std::fixed << std::setprecision(1) << tempo << " segundos." << std::endl;
}

void FilaProcessos::imprimir_fila(){
    Processo* atual = head;
    while(atual != nullptr){
        atual->imprimir_dados();
        atual = atual->next;
    }
}