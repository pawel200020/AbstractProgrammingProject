//
// Created by p1 on 02/01/2023.
//

#include "Attacker.hpp"

Attacker::Attacker(std::string name, std::string lastName, int age, std::string team, double power, double accuracy)
        : Player(name, lastName, age, team, power), _accuracy(accuracy) {}

bool Attacker::Shoot(GoalKeeper goalKeeper) {
    srand(time(nullptr));
    int shooterScore = _power + _accuracy;
    int defenderScore = goalKeeper.GetDefenceAccuracy();
    int result = rand() % (shooterScore + defenderScore - 1 + 1) + 1;
    if (result < shooterScore) {
        return true;
    }
    return false;
}

double Attacker::GetAccuracy() {

    return _accuracy;
}

bool Attacker::Pass(Attacker attacker, Attacker opponent) {
    srand(time(nullptr));
    int currTeamScore = _power + _accuracy + attacker._power + attacker._accuracy;
    int opponentScore = (opponent._accuracy + opponent._power) * 2;
    if (currTeamScore >= opponentScore) {
        return true;
    }
    return false;


}
