#include "Enemigo.h"
#include <cstdlib>

Enemigo::Enemigo(int pVida, std::string pNombre, int pDanio, int pDefensa)
    : Personaje(pVida, pNombre, pDanio), defensa(pDefensa) {}

int Enemigo::getDanio() {
    return rand() % 201; // Daño del enemigo: número aleatorio entre 0 y 200
}

int Enemigo::getDefensa() {
    return defensa;
}

void Enemigo::setDefensa(int pDefensa) {
    defensa = pDefensa;
}

void Enemigo::printStatus() {
    std::cout << "Nombre del enemigo: " << getNombre() << "\n"
        << "Vida: " << getVida() << "\n"
        << "Defensa: " << getDefensa() << std::endl;
}
