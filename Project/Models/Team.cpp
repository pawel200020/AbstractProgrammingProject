//
// Created by p1 on 02/01/2023.
//

#include "Team.hpp"
#include "Defender.hpp"
#include "GoalKeeper.hpp"
#include "Attacker.hpp"
#include <utility>
#include <iostream>
#include <synchapi.h>

Team::Team(std::vector<Player *> *players, std::vector<Fan *> *fans) :
                                                                       _fans(std::move(fans)) {}

Team::Team(std::list<std::string> *playersNames, std::list<std::string> *playersLastNames,
           std::list<std::string> *fanNames, std::list<std::string> *fanLastNames, std::string name) {
    defenders = new std::vector<Defender*>;
    attackers = new std::vector<Attacker*>;
    _players = new std::vector<Player *>;

    _fans = new std::vector<Fan *>;
    _name = name;
    auto lastNameFanPointer = fanLastNames->begin();
    srand(time(nullptr));
    for (auto elem = fanNames->begin(); elem != fanNames->end(); ++elem) {
        std::string noise = "ahoj " + *elem + " to my favourite team " + name;
        _fans->push_back(new Fan(*elem, *lastNameFanPointer, rand() % (80 - 1 + 1) + 1, name, noise));
        lastNameFanPointer++;
    }
    auto lastNamePlayerPointer = playersLastNames->begin();
    int sumControl = 0;
    for (auto elem = playersNames->begin(); elem != playersNames->end(); elem++) {
        if (sumControl == 0) {
            goalKeeper = new GoalKeeper(*elem, *lastNamePlayerPointer, rand() % (60 - 20 + 1) + 20, name,
                                        rand() % (10 - 1 + 1) + 1, rand() % (10 - 1 + 1) + 1);
             _players->push_back(goalKeeper);
        }
        if (sumControl > 0 && sumControl < 5) {
            auto defender = new Defender(*elem, *lastNamePlayerPointer, rand() % (60 - 20 + 1) + 20, name,
                                         rand() % (10 - 1 + 1) + 1, rand() % (10 - 1 + 1) + 1);
            defenders->push_back(defender);
            _players->push_back(defender);
        } else {
            auto attacker = new Attacker(*elem, *lastNamePlayerPointer, rand() % (60 - 20 + 1) + 20, name,
                                         rand() % (10 - 1 + 1) + 1, rand() % (10 - 1 + 1) + 1);
            attackers->push_back(attacker);
            _players->push_back(attacker);
        }
        sumControl++;
        lastNamePlayerPointer++;
    }
}

void Team::PrintTeam() {
    for (auto i = _fans->begin(); i != _fans->end(); i++) {
        std::cout << (*i)->Stats();
    }
    int sumControl = 0;
    std::cout << '\n';
    for (auto i = _players->begin(); i != _players->end(); i++) {

        if (sumControl == 0) {
            std::cout << "Goalkeeper: " << (*i)->Stats();
        } else if (sumControl > 0 && sumControl < 5) {
            std::cout << "Defender: " << (*i)->Stats();
        } else {
            std::cout << "Attacker: " << (*i)->Stats();
        }
        sumControl++;
    }
}

void Team::ShotAPenalty(Team *team,Attacker * attacker) {
    srand(time(nullptr));
    GoalKeeper *g1 = team->goalKeeper;
    int attackerNumber = rand() % (6 - 0 + 1) + 0;
    int fanPower = rand() % (11 - 1 + 1) + 1;
    Attacker * shooter;
    if(attacker== nullptr){
        shooter = attackers->at(attackerNumber);
    }
    else{
        shooter=attacker;
    }
    std::cout<<"\nthe shooter will be: "<<*shooter<<" with accuracy: "<<shooter->GetAccuracy()<<"\n";
    std::cout<<"the GoalKeeper will be: "<<*g1<<" with defence accuracy: "<<g1->GetDefenceAccuracy()<<"\n\n";
    Sleep(1000);
    auto result = shooter->Shoot(*g1);
    if(result){
        std::cout<<"What a wonderful shoot "<<*shooter<<" made it perfect\n\n";
        Sleep(1000);
        score++;
        for(int i = 0; i < fanPower; i++){

            std::cout<<_fans->at(i)->MakeSomeNoise()<<" great shoot"<<'\n';
            Sleep(500);
        }
        return;
    }
    std::cout<<"What a great defence "<<*g1<<" defended it clearly\n";
    for(int i = 0; i < fanPower; i++){

        std::cout<<_fans->at(i)->MakeSomeNoise()<<" I knew that he can do this!"<<'\n';
        Sleep(500);
    }
}

void Team::MakeShortAction(Team *team) {
    std::cout<<"teeam named: "<<_name<<" is starting an action\n";
    srand(time(nullptr));
    Attacker * shooter;
    int stepsNumber = rand() % (3 - 1 + 1) + 1;
    int attackerNumber = rand() % (6 - 0 + 1) + 0;
    for(int i = 0; i < stepsNumber; i++){
        shooter = attackers->at(attackerNumber);
        std::cout<<"\nthe shooter: "<<*shooter<<" has a ball let us sew what happens\n";
        Sleep(1000);
        int temp = rand() % (6 - 0 + 1) + 0;
        while(temp==attackerNumber){
            temp =  rand() % (6 - 0 + 1) + 0;
        }
        auto receiverNumber = temp;
        Attacker * receiver = attackers->at(receiverNumber);
        Attacker * opponent = team->attackers->at(receiverNumber);
        std::cout<<"He is going to pass to "<<*receiver<<"\nbut opponent: "<<*opponent<<" may want to interupt this action\n";
        Sleep(1000);
        bool result = shooter->Pass(*receiver, *opponent);
        if(result){
            std::cout<<"Nice shoot let's look what he will do now\n";
        }
        else{
            std::cout<<"This is the end of an action oponent has captured a ball.\n";
            return;
        }
        Sleep(5000);

        attackerNumber=receiverNumber;
    }
    shooter = attackers->at(attackerNumber);
    std::cout<<"Action finished fluently, now he is going to shoot a goal!\n\n";
    Sleep(2000);
    ShotAPenalty(team,shooter);

}

