//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_TEAM_HPP
#define PROJECT_TEAM_HPP


#include <list>
#include <set>
#include <vector>
#include "Player.hpp"
#include "Fan.hpp"
#include "GoalKeeper.hpp"
#include "Defender.hpp"
#include "Attacker.hpp"

class Team {
public:
    std::vector<Player *> *_players;
    GoalKeeper* goalKeeper;
    std::vector<Defender*>* defenders;
    std::vector<Attacker*>* attackers;
    std::vector<Fan *> *_fans;
    std::string _name;
    int score = 0;

    Team(std::vector<Player *> *players, std::vector<Fan *> *fans);

    Team(std::list<std::string> *playersNames, std::list<std::string> *playersLastNames,
         std::list<std::string> *fanNames, std::list<std::string> *fanLastNames, std::string name);

    void PrintTeam();
    void ShotAPenalty(Team* team, Attacker * attacker = nullptr);
    void MakeShortAction(Team* team);

};


#endif //PROJECT_TEAM_HPP
