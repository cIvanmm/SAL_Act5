#ifndef NEURONA_H
#define NEURONA_H

class Neurona{
private:
    int id;
    float voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;
public:
    Neurona(int, float, int, int, int, int, int);
    void print();
    int getid();
    float getvoltaje();
    int getx();
    int gety();
    int getred();
    int getgreen();
    int getblue();
};

#endif // NEURONA_H
