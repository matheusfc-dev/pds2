#ifndef RINGARRAY_HPP
#define RINGARRAY_HPP

#include <iostream>
#include <vector>

template<class T>
class RingArray { // declaracao
    
    private:
        std::vector<T> _buffer;
        int _capacidade;
        int _tamanho;  
        int _head = 0;
        int _tail = 0;
    public:
        RingArray(int capacidade);
        void push(T item);
        T get(int index);
        T pop();
        void print();
        T get_maior();
        int size();
        bool is_empty();
        bool is_full(); 
};


// implementacoes

template <class T>
RingArray<T>::RingArray(int capacidade)
    : _buffer(capacidade), _capacidade(capacidade), _tamanho(0) {}

template <class T>
void RingArray<T>::push(T item){

    if(is_full()){
        _head = (_head + 1) % _capacidade;
    }
    else{
        _tamanho++;
        }

    _tail = (_head + _tamanho - 1) % _capacidade;
    _buffer[_tail] = item;

}

template <class T>
T RingArray<T>::get(int index){
    return _buffer[(_head + index) % _capacidade];
}

template <class T>
T RingArray<T>::pop(){
    T removido = _buffer[_head];

    _head = (_head + 1) % _capacidade;
    _tamanho--;

    return removido;
}

template<class T>
void RingArray<T>::print() {
    for (int i = 0; i < _tamanho; i++) {
        std::cout << get(i) << std::endl;
    }
}

template<class T>
T RingArray<T>::get_maior() {
    T maior = get(0);

    for (int i = 1; i < _tamanho; i++) {
        if (get(i) > maior) {
            maior = get(i);
        }
    }

    return maior;
}

template <class T>
int RingArray<T>::size(){
    return _tamanho;
}

template <class T>
bool RingArray<T>::is_empty(){
    if(_tamanho > 0){
        return false;
    }
    return true;
}

template <class T>
bool RingArray<T>::is_full(){
    if(_tamanho == _capacidade){
        return true;
    }
    return false;
}

#endif