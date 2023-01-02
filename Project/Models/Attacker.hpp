//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_ATTACKER_HPP
#define PROJECT_ATTACKER_HPP


#include "Player.hpp"

class Attacker : public Player{
protected:
    double _accuracy;
public:
    Attacker(std::string name, std::string lastName, int age, std::string team, double power, double accuracy);
    bool Shoot();
};


#endif //PROJECT_ATTACKER_HPP
