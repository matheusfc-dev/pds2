#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            _tabuleiro[i][j] = ' ';
        }
    }
}

bool Tabuleiro::validaJogada(int linha, int coluna, char simbolo){

    if(linha >= 0 && linha <= 2 && coluna >= 0 && coluna <=2){
        if(simbolo == 'X' || simbolo == 'O'){
            if(_tabuleiro[linha][coluna] == ' '){
                return true;
            }
        }
    }
    return false;
}

void Tabuleiro::fazerJogada(int linha, int coluna, char simbolo){
    if(Tabuleiro::validaJogada(linha,coluna,simbolo) == true){
        _tabuleiro[linha][coluna] = simbolo;
    }
}

char Tabuleiro::verificarEstadoPartida(){
    
    for(int i = 0; i < 2; i++){
        if(
            _tabuleiro[i][0] != ' '
            && _tabuleiro[i][0] == _tabuleiro[i][1]
            && _tabuleiro[i][1] == _tabuleiro[i][2]
        ){
            if(_tabuleiro[i][0] == 'X'){
                return 'X';
            }
            return 'O';
        }
    }

    for(int j = 0; j < 2; j++){
        if(
            _tabuleiro[0][j] != ' '
            && _tabuleiro[0][j] == _tabuleiro[1][j]
            && _tabuleiro[1][j] == _tabuleiro[2][j]
        ){
            if(_tabuleiro[0][j] == 'X'){
                return 'X';
            }
            return 'O';
        }
    }

    if(
        _tabuleiro[0][0] == _tabuleiro[1][1]
        && _tabuleiro[1][1] == _tabuleiro[2][2]
        && _tabuleiro[0][0] != ' '
    ){
        if(_tabuleiro[0][0] == 'X'){
            return 'X';
        }
        return 'O';
    }

    if(
        _tabuleiro[0][2] == _tabuleiro[1][1]
        && _tabuleiro[1][1] == _tabuleiro[2][0]
        && _tabuleiro[0][2] != ' '
    ){
        if(_tabuleiro[0][2] == 'X'){
            return 'X';
        }
        return 'O';
    }

    bool temVazio = false;
    for(int k = 0; k < 2; k++){
        for (int l = 0; l < 2; l++){
            if(_tabuleiro[k][l] == ' '){
                temVazio = true;
            }
        }
    }
    if(!temVazio){ return 'E';}

    return 'P';
}

void Tabuleiro::imprimir(){
    for (int i = 0; i < 3; i++) {
        std::cout << " " << _tabuleiro[i][0] << " | "
                  << _tabuleiro[i][1] << " | "
                  << _tabuleiro[i][2] << "\n";
        if (i < 2)
            std::cout << "-----------\n";
    }
}