#include "listaneuronas.h"

ListaNeuronas::ListaNeuronas()
{

}

void ListaNeuronas::agregar_inicio(Neurona neurona){
    neuronas.insert(0, neurona);
}

void ListaNeuronas::agregar_final(Neurona neurona){
    neuronas.push_back(neurona);
}

int ListaNeuronas::cant_neuronas(){
    return neuronas.size();
}

int ListaNeuronas::getnid(int i){
    int dato =neuronas[i].getid();
    return dato;
}

float ListaNeuronas::getnvoltaje(int i){
    float dato =neuronas[i].getvoltaje();
    return dato;
}

int ListaNeuronas::getnx(int i){
    int dato =neuronas[i].getx();
    return dato;
}

int ListaNeuronas::getny(int i){
    int dato =neuronas[i].gety();
    return dato;
}

int ListaNeuronas::getnred(int i){
    int dato =neuronas[i].getred();
    return dato;
}

int ListaNeuronas::getngreen(int i){
    int dato =neuronas[i].getgreen();
    return dato;
}

int ListaNeuronas::getnblue(int i){
    int dato =neuronas[i].getblue();
    return dato;
}
