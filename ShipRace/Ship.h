#pragma once
#include <iostream>
#include <string>

class Ship {
private:
    int Speed;
    int Distance;
    bool Nitro;
    bool UsedNitro;
    std::string Name;

public:
    Ship();
    Ship(int pSpeed, int pDistance, bool pNitro, std::string pName);

    int getSpeed() const;
    void setSpeed(int pSpeed);

    int getDistance() const;
    void setDistance(int pDistance);

    bool hasNitro() const;
    void setNitro(bool pNitro);

    bool hasUsedNitro() const;
    void setUsedNitro(bool pUsedNitro);

    std::string getName() const;
    void setName(std::string pName);

    void rollDice();
    void useNitro();
    void calculateDistance();
};