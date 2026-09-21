#include "BaseMilitar.hpp"
#include "Canhao.hpp"
#include "CanhaoOrbital.hpp"
#include "LancadorMissil.hpp"

#include <iostream>
#include <string>

int main(){

    std::string endstring = "s";
    std::string canhao = "c";
    std::string orbital = "o";
    std::string missil = "m";
    std::string defesa = "d";

    std::string entrada;

    BaseMilitar base;


    while(std::cin >> entrada && entrada != endstring){

        if(entrada == canhao){
            int id;
            double energia;
            double intensidade;
            std::cin >> id;
            std::cin >> energia;
            std::cin >> intensidade;


            Canhao* c = new Canhao(id,energia,intensidade);
            base.adicionarDefesa(c);
        }
        else if(entrada == orbital){
            int id;
            double energia,intensidade,gravidade;
            std::cin >> id >> energia >> intensidade >> gravidade;


            CanhaoOrbital* o = new CanhaoOrbital(id,energia,intensidade,gravidade);
            base.adicionarDefesa(o);
        }
        else if(entrada == missil){
            int id, qtd_misseis;
            double energia;
            std::cin >> id >> energia >> qtd_misseis;


            LancadorMissil* m = new LancadorMissil(id, energia, qtd_misseis);
            base.adicionarDefesa(m);
        }
        else if(entrada == defesa){
            double vida_inimigo;
            std::cin >> vida_inimigo;
            base.defender(vida_inimigo);
        }

    }

    return 0;
}