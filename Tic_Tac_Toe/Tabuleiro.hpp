#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <iostream>


class Tabuleiro{
    public:
        char _tabuleiro[3][3];

        Tabuleiro();
        bool validaJogada(int linha, int coluna, char simbolo);
        void fazerJogada(int linha, int coluna, char simbolo);
        char verificarEstadoPartida();
        void imprimir();
};

#endif