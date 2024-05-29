#include "Personaje.h"

Personaje::Personaje(int pVida, std::string pNombre, int pDanio)
    : vida(pVida), nombre(pNombre), danio(pDanio) {}

int Personaje::getVida() {
    return vida;
}

void Personaje::setVida(int pVida) {
    vida = pVida;
}

std::string Personaje::getNombre() {
    return nombre;
}

void Personaje::setNombre(std::string pNombre) {
    nombre = pNombre;
}
