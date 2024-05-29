#pragma once
#include "Personaje.h"
#include <iostream>

class Enemigo : public Personaje {
private:
    int defensa;

public:
    Enemigo(int pVida, std::string pNombre, int pDanio, int pDefensa);
    int getDanio() override;
    int getDefensa();
    void setDefensa(int pDefensa);
    void printStatus();
};
