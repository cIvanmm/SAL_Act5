#include "neurona.h"

Neurona::Neurona(int id, float voltaje, int posicion_x, int posicion_y, int red, int green, int blue)
{
    this ->id =id;
    this ->voltaje =voltaje;
    this ->posicion_x =posicion_x;
    this ->posicion_y =posicion_y;
    this ->red =red;
    this ->green =green;
    this ->blue =blue;
}

int Neurona::getid(){
    return id;
}

float Neurona::getvoltaje(){
    return voltaje;
}

int Neurona::getx(){
    return posicion_x;
}

int Neurona::gety(){
    return posicion_y;
}

int Neurona::getred(){
    return red;
}

int Neurona::getgreen(){
    return green;
}

int Neurona::getblue(){
    return blue;
}
