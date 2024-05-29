#include "Heroe.h"
#include <cstdlib>

Heroe::Heroe(int pVida, std::string pNombre, int pDanio)
    : Personaje(pVida, pNombre, pDanio) {}

int Heroe::getDanio() {
    return rand() % 201 + 50; // Daño del héroe: número aleatorio entre 50 y 250
}

void Heroe::printStatus() {
    std::cout << "Nombre del héroe: " << getNombre() << "\n"
        << "Vida: " << getVida() << std::endl;
}
