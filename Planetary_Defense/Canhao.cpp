#include "Canhao.hpp"

Canhao::Canhao(int id, double energia, double intensidade) : Defesa(id, energia), _intensidade(intensidade) {}

void Canhao::atacar(double &danoAcumulado){
    if(_getEnergia() >= 10){
        _consumirEnergia(10);
        danoAcumulado += _intensidade;
    }
    
}