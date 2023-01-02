//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_TEAM_HPP
#define PROJECT_TEAM_HPP


#include <list>
#include <set>
#include "Player.hpp"
#include "Fan.hpp"

class Team {
public:
    std::list<Player*>* _players;
    std::list<Fan*>* _fans;
    Team(std::list<Player*>* players, std::list<Fan*>* fans);
    Team(std::list<std::string>* playersNames, std::list<std::string>* fanNames);

};


#endif //PROJECT_TEAM_HPP
