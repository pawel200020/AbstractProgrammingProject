//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_PLAYER_HPP
#define PROJECT_PLAYER_HPP
#include "Human.hpp"

class Player: public Human{
protected:
    std::string _team;
    double _power;
public:
    Player(std::string name, std::string lastName, int age, std::string team, double power);
    virtual void print(std::ostream &where) const;
};


#endif //PROJECT_PLAYER_HPP
