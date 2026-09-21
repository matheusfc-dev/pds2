#ifndef DEFESA_HPP
#define DEFESA_HPP

class Defesa{
    private:
        int _id;
        double _energia;
    protected:
        void _consumirEnergia(double qtd);
        double _getEnergia();
    public:
        Defesa(int id, double energia);
        virtual void atacar(double &danoAcumulado) = 0;
        ~Defesa();
};





#endif