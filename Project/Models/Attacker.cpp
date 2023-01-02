//
// Created by p1 on 02/01/2023.
//

#include "Attacker.hpp"

Attacker::Attacker(std::string name, std::string lastName, int age, std::string team, double power, double accuracy) : Player(name, lastName, age,team, power), _accuracy(accuracy){}

bool Attacker::Shoot() {
    return false;
}
