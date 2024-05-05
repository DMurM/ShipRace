#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Ship.h"

void printSeparator() {
    std::cout << "---------------------------------\n";
}

void printTurnInfo(int turno, const Ship& lancha1, const Ship& lancha2) {
    printSeparator();
    std::cout << "Turno " << turno << "\n";
    std::cout << "Estado de las lanchas:\n";
    std::cout << lancha1.getName() << " - Velocidad: " << lancha1.getSpeed() << ", Distancia: " << lancha1.getDistance() << "\n";
    std::cout << lancha2.getName() << " - Velocidad: " << lancha2.getSpeed() << ", Distancia: " << lancha2.getDistance() << "\n";
    printSeparator();
}

int main() {
    srand(time(0));

    // Crear las instancias de las lanchas
    Ship lancha1(0, 0, true, "Lancha 1");
    Ship lancha2(0, 0, true, "Lancha 2");

    // Bucle de los cinco turnos
    for (int turno = 1; turno <= 5; turno++) {
        lancha1.setUsedNitro(false);
        lancha2.setUsedNitro(false);

        // Limpiar la pantalla al inicio de cada turno
        system("cls"); 

        std::cout << "Turno de " << lancha1.getName() << ". Presiona Enter para lanzar el dado.\n";
        std::cin.get();
        lancha1.rollDice();
        printTurnInfo(turno, lancha1, lancha2);

        char choice;
        std::cout << "Quieres usar nitro en este turno para " << lancha1.getName() << "? (S/N): ";
        std::cin >> choice;
        if (toupper(choice) == 'S') {
            lancha1.useNitro();
            std::cout << lancha1.getName() << " ha usado nitro.\n";
        }

        lancha1.calculateDistance();
        lancha2.calculateDistance();

        std::cout << "Turno de " << lancha2.getName() << ". Presiona Enter para lanzar el dado.\n";
        std::cin.get(); 
        std::cin.get();
        lancha2.rollDice();
        printTurnInfo(turno, lancha1, lancha2);

        // Preguntar al jugador si desea usar nitro para la lancha 2
        std::cout << "Quieres usar nitro en este turno para " << lancha2.getName() << "? (S/N): ";
        std::cin >> choice;
        if (toupper(choice) == 'S') {
            lancha2.useNitro();
            std::cout << lancha2.getName() << " ha usado nitro.\n";
        }

        // Calcular la distancia recorrida al final de cada turno
        lancha1.calculateDistance();
        lancha2.calculateDistance();
    }

    //Final
    std::cout << "Resultado final:\n";
    std::cout << lancha1.getName() << " recorrio " << lancha1.getDistance() << " metros.\n";
    std::cout << lancha2.getName() << " recorrio " << lancha2.getDistance() << " metros.\n";
    if (lancha1.getDistance() > lancha2.getDistance()) {
        std::cout << lancha1.getName() << " gana!\n";
    }
    else if (lancha1.getDistance() < lancha2.getDistance()) {
        std::cout << lancha2.getName() << " gana!\n";
    }
    else {
        std::cout << "Empate!\n";
    }

    return 0;
}