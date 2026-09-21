#ifndef BASEMILITAR_HPP
#define BASEMILITAR_HPP

#include "Defesa.hpp"

class BaseMilitar {
    private:
        Defesa* _defesas[100] = {nullptr};
        int _qtdAtual = 0;

    public:
        void adicionarDefesa(Defesa* d);
        void defender(double &saudeInimigo);
        ~BaseMilitar();

};

#endif