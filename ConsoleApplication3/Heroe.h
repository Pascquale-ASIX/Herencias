#pragma once
#include "Personaje.h"
#include <iostream>

class Heroe : public Personaje {
public:
    Heroe(int pVida, std::string pNombre, int pDanio);
    int getDanio() override;
    void printStatus();
};
