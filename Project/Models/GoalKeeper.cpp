//
// Created by p1 on 02/01/2023.
//

#include "GoalKeeper.hpp"

GoalKeeper::GoalKeeper(std::string name, std::string lastName, int age, std::string team, double power,
                       double defenceAccuracy) : Player(name, lastName, age, team, power),
                                                 _defenceAccuracy(defenceAccuracy) {
}

double GoalKeeper::GetDefenceAccuracy() {
    return _defenceAccuracy;
}

double GoalKeeper::getScore() {
    return _power + _defenceAccuracy;
}
