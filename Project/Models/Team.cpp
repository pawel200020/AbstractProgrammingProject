//
// Created by p1 on 02/01/2023.
//

#include "Team.hpp"

#include <utility>

Team::Team(std::list<Player*>* players, std::list<Fan*>* fans): _players(std::move(players)), _fans(std::move(fans)) {}

Team::Team(std::list<std::string>* playersNames, std::list<std::string>* fanNames) {
    _players = new std::list<Player*>;
//    for (auto elem = playersNames->begin(); elem != playersNames->end(); ++elem){
//        _players->push_back(new Player(*elem,"player",))
//    }
}

