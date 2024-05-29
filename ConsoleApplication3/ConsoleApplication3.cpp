#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <thread> 
#include <chrono> 
#include "Enemigo.h"
#include "Heroe.h"

using namespace std;

void printBoard(char board[5][5]) {
    for (int i = 0; i < 5; i++) {
        cout << "| ";
        for (int j = 0; j < 5; j++) {
            cout << board[i][j] << " | ";
        }
        cout << '\n';
        cout << "---------------------\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Para generar números aleatorios

    string nombreHeroe;
    int movimiento;
    int posX = 2, posY = 2; // Posición inicial del héroe en el centro del tablero

    char board[5][5] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    // Generar la posición del jefe aleatoriamente
    int bossX, bossY;
    do {
        bossX = rand() % 5;
        bossY = rand() % 5;
    } while (bossX == posX && bossY == posY); // Asegurarse de que el jefe no aparezca en la casilla de inicio del héroe

    board[bossY][bossX] = 'B'; // Colocar al boss

    cout << "Introduce el nombre de tu heroe: ";
    cin >> nombreHeroe;

    cout << "Bienvenido, " << nombreHeroe << "! Ahora puedes moverte.\n";
    cout << "Usa las teclas de flecha para moverte (presiona 'q' para salir): ";

    Heroe heroe(250, nombreHeroe, 0); // Héroe con 250 de vida
    Enemigo jefe(500, "Jefe", 0, 100); // Jefe con 500 de vida

    while (true) {
        system("cls");
        printBoard(board);

        movimiento = _getch();

        if (movimiento == 'q') {
            break;
        }

        if (movimiento == 224 || movimiento == 0) { // Se presionó una tecla de flecha
            movimiento = _getch(); 
        }

        // Borrar la posición actual del héroe
        board[posY][posX] = ' ';

        switch (movimiento) {
        case 72: // Arriba
            if (posY > 0) posY--;
            break;
        case 80: // Abajo
            if (posY < 4) posY++;
            break;
        case 75: // Izquierda
            if (posX > 0) posX--;
            break;
        case 77: // Derecha
            if (posX < 4) posX++;
            break;
        default:
            cout << "Movimiento no reconocido.\n";
            break;
        }

        // Comprobar si el héroe ha entrado en la casilla del jefe
        if (posX == bossX && posY == bossY) {
            cout << "Has encontrado al jefe! Empieza el combate...\n";

            while (heroe.getVida() > 0 && jefe.getVida() > 0) {
                int danioHeroe = heroe.getDanio();
                int danioJefe = jefe.getDanio();

                jefe.setVida(jefe.getVida() - danioHeroe);
                heroe.setVida(heroe.getVida() - danioJefe);

                cout << nombreHeroe << " hace " << danioHeroe << " puntos de danyo! \n Vida del jefe: " << max(0, jefe.getVida()) << "\n";
                cout << "El jefe hace " << danioJefe << " puntos de danyo! \n Vida de " << nombreHeroe << ": " << max(0, heroe.getVida()) << "\n";

                // Añadir un retraso de 3 segundos entre los movimientos
                this_thread::sleep_for(chrono::seconds(3));
            }

            if (heroe.getVida() > 0) {
                cout << "Has derrotado al jefe! Felicidades!\n";
            }
            else {
                cout << "Has sido derrotado por el jefe. Mejor suerte la proxima vez.\n";
            }

            break;
        }

        // Actualizar la posición del héroe
        board[posY][posX] = 'X';
    }

    cout << "Gracias por jugar, " << nombreHeroe << "!\n";

    return 0;
}
