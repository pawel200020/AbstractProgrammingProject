//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_GOALKEEPER_HPP
#define PROJECT_GOALKEEPER_HPP

#include "Player.hpp"

class GoalKeeper : public Player {
protected:
    const double _defenceAccuracy;
public:
    GoalKeeper(std::string name, std::string lastName, int age, std::string team, double power, double defenceAccuracy);

    double GetDefenceAccuracy();

    double getScore();
};


#endif //PROJECT_GOALKEEPER_HPP
