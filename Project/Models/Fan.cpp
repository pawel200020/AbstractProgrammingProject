//
// Created by p1 on 02/01/2023.
//
#include "Fan.hpp"

Fan::Fan(std::string name, std::string lastName, int age, std::string favouriteTeam, std::string favouriteCheer)
        : Human(name, lastName, age),
          _favouriteCheer(favouriteCheer),
          _favouriteTeam(favouriteTeam) {

}

std::string Fan::MakeSomeNoise() {
    std::stringstream res;
    res << _name << ": " << _favouriteCheer << " " << '\n';
    return res.str();
}

void Fan::print(std::ostream &where) const {
    where << "Fan named: " << _name << " " << _lastName << "aged: " << _age << '\n';
}

std::string Fan::Stats() {
    std::stringstream res;
    res << "Fan of " << _favouriteTeam << " named " << _name << " " << _lastName << " aged " << _age
        << " his favourite cheer is: " << _favouriteCheer << '\n';
    return res.str();
}

