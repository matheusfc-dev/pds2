#include "Partida.hpp"
#include <iostream>



/*Partida::Partida(Jogador jogador1, Jogador jogador2){
    _jogador1 = jogador1;
    _jogador2 = jogador2;
    _atual = &_jogador1;

}*/

Partida::Partida(Jogador jogador1, Jogador jogador2) : _jogador1(jogador1), _jogador2(jogador2), _atual(&_jogador1) {}

Jogador& Partida::getJogadorAtual(){
    return *_atual;
}

void Partida::executarJogada(int linha, int coluna){
    if(tabuleiro.validaJogada(linha, coluna, _atual->_simbolo) == true){
        tabuleiro.fazerJogada(linha,coluna, _atual->_simbolo);
        if(_atual == &_jogador1){
            _atual = &_jogador2;
        }
        else{
            _atual = &_jogador1;
        }
    }
    else{
        std::cout << "Jogada invalida!\n";
    }
}

char Partida::statusPartida(){
    return tabuleiro.verificarEstadoPartida();
}

void Partida::exibirPartida(){
    tabuleiro.imprimir();
}



