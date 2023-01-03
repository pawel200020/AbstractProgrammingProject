//
// Created by p1 on 02/01/2023.
//

#include "Player.hpp"

Player::Player(std::string name, std::string lastName, int age, std::string team, double power) : Human(name,lastName, age), _team(team), _power(power){}

void Player::print(std::ostream &where) const {
    where<<"Player named: "<<_name<<" "<<_lastName<<" aged: "<<_age<<" with power: "<<_power;
}

std::string Player::Stats() {
    std::stringstream res;
    res<<"player of "<<_team<<" named "<<_name<<" "<<_lastName<<" and his power is: "<<_power<<'\n';
    return res.str();
}
