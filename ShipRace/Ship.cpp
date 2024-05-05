#include "Ship.h"
#include <random> 

Ship::Ship()
    : Speed(0), Distance(0), Nitro(true), UsedNitro(false), Name("default") {
}

Ship::Ship(int pSpeed, int pDistance, bool pNitro, std::string pName)
    : Speed(pSpeed), Distance(pDistance), Nitro(pNitro), UsedNitro(false), Name(pName) {
}

int Ship::getSpeed() const {
    return Speed;
}

void Ship::setSpeed(int pSpeed) {
    Speed = pSpeed;
}

int Ship::getDistance() const {
    return Distance;
}

void Ship::setDistance(int pDistance) {
    Distance = pDistance;
}

bool Ship::hasNitro() const {
    return Nitro;
}

void Ship::setNitro(bool pNitro) {
    Nitro = pNitro;
}

bool Ship::hasUsedNitro() const {
    return UsedNitro;
}

void Ship::setUsedNitro(bool pUsedNitro) {
    UsedNitro = pUsedNitro;
}

std::string Ship::getName() const {
    return Name;
}

void Ship::setName(std::string pName) {
    Name = pName;
}

void Ship::rollDice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 6);
    int dice = dis(gen);
    Speed += dice;
}

//Validar el nitro
void Ship::useNitro() {
    if (!Nitro || UsedNitro) {
        std::cout << "No puedes usar el nitro en este turno para " << Name << "!\n";
        return;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 1);
    int random = dis(gen);
    if (random == 0) {
        Speed /= 2; // Dividir la velocidad por dos
    }
    else {
        Speed *= 2; // Duplicar la velocidad
    }
    Nitro = false; // Desactivar el nitro
    UsedNitro = true; // Marcar que el nitro ha sido usado en la partida
}

void Ship::calculateDistance() {
    Distance += Speed * 100; // Calcular la distancia recorrida
}