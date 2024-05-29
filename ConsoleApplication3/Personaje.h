#pragma once
#include <string>

class Personaje {
protected:
    int vida;
    std::string nombre;
    int danio;

public:
    Personaje(int pVida, std::string pNombre, int pDanio);
    int getVida();
    void setVida(int pVida);
    std::string getNombre();
    void setNombre(std::string pNombre);
    virtual int getDanio() = 0; 
};
