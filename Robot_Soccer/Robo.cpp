#include "Robo.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

Robo::Robo(int id, Ponto2D posicao, bool com_bola) {
    _id = id;
    _posicao = posicao;
    _com_bola = com_bola;
    _energia = 100.0; 
}

void Robo::mover(double v, double th, double t) {
    double d = v * t;
    _posicao._x += d * std::cos(th);
    _posicao._y += d * std::sin(th);
    _energia -= d;
}

double Robo::calcular_distancia(Robo* robo) {
    return _posicao.calcular_distancia(&(robo->_posicao));
}

Robo* Robo::determinar_robo_mais_proximo(Robo** naves, int n) {
    Robo* mais_proximo = nullptr;
    double menor_distancia = -1.0;

    for (int i = 0; i < n; ++i) {
        if (naves[i] != this) {
            double dist = calcular_distancia(naves[i]);
            if (mais_proximo == nullptr || dist < menor_distancia) {
                menor_distancia = dist;
                mais_proximo = naves[i];
            }
        }
    }

    return mais_proximo;
}

void Robo::passar_bola(Robo** time, int n) {
    if (!_com_bola) {
        std::cout << "Estou sem a bola!" << std::endl;
        return;
    }

    Robo* destino = determinar_robo_mais_proximo(time, n);
    if (destino != nullptr) {
        _com_bola = false;
        destino->_com_bola = true;
    }
}

void Robo::imprimir_status() {
    std::cout << _id << "\t"
              << _posicao._x << "\t"
              << _posicao._y << "\t"
              << _com_bola << "\t"
              << _energia << std::endl;
}