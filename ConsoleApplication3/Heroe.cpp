#include "Heroe.h"
#include <cstdlib>

Heroe::Heroe(int pVida, std::string pNombre, int pDanio)
    : Personaje(pVida, pNombre, pDanio) {}

int Heroe::getDanio() {
    return rand() % 201 + 50; // Da�o del h�roe: n�mero aleatorio entre 50 y 250
}

void Heroe::printStatus() {
    std::cout << "Nombre del h�roe: " << getNombre() << "\n"
        << "Vida: " << getVida() << std::endl;
}
