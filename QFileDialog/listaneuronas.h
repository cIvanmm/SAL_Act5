#ifndef LISTANEURONAS_H
#define LISTANEURONAS_H

#include<QVector>
#include"neurona.h"

class ListaNeuronas{
private:
    QVector<Neurona> neuronas;
public:
    ListaNeuronas();
    void agregar_inicio(Neurona);
    void agregar_final(Neurona);
    int cant_neuronas();
    int getnid(int);
    float getnvoltaje(int);
    int getnx(int);
    int getny(int);
    int getnred(int);
    int getngreen(int);
    int getnblue(int);
};

#endif // LISTANEURONAS_H
