//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_DEFENDER_HPP
#define PROJECT_DEFENDER_HPP
#include "Player.hpp"

class Defender: public Player {
protected:
    double _defenceAccuracy;
public:
    Defender(std::string name, std::string lastName, int age, std::string team, double power, double defenceAccuracy);

    bool Defend();
};


#endif //PROJECT_DEFENDER_HPP
