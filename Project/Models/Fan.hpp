//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_FAN_HPP
#define PROJECT_FAN_HPP

#include "Human.hpp"

class Fan : public Human {
protected:
    std::string _favouriteTeam;
    std::string _favouriteCheer;
public:
    Fan(std::string name, std::string lastName, int age, std::string favouriteTeam, std::string favouriteCheer);

    std::string MakeSomeNoise();

    std::string Stats();

    virtual void print(std::ostream &where) const;
};


#endif //PROJECT_FAN_HPP
