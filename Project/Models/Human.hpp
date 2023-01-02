//
// Created by p1 on 02/01/2023.
//

#ifndef PROJECT_HUMAN_HPP
#define PROJECT_HUMAN_HPP


#include <string>
#include <iostream>
#include <sstream>
class Human {
protected:
    std::string _name;
    std::string _lastName;
    int _age;
public:
    Human(std::string name, std::string lastName, int age );
    virtual void print(std::ostream& where) const=0;
    friend std::ostream& operator<<(std::ostream& str, Human const& data)
    {
        data.print(str);
        return str;
    }
};


#endif //PROJECT_HUMAN_HPP
