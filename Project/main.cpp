#include <iostream>
#include <list>
#include <fstream>
#include "Models/Player.hpp"
#include "Models/Fan.hpp"
#include "Models/Team.hpp"

template<int N> inline void loop(int *data) {
    if(data[0]>data[1]) std::swap(data[0],data[1]);
    loop<N-1>(++data);
}
template<> inline void loop<0>(int *data) {};

template<int N> inline void bubble_sort_template(int * data) {
    loop<N-1>(data);
    bubble_sort_template<N-1>(data);
}
template<> inline void bubble_sort_template<2>(int * data) {
    loop<1>(data);
};
template<typename T>
std::list<T>* readFromFileToList(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    T line;
    auto result = new std::list<T>;
    file >> line;
    while (!file.eof()) {
        result->push_back(line);
        file >> line;
    }
    return result;
}
template<typename T>
void printList(std::list<T> const &list)
{
    for (auto const &i: list) {
        std::cout << i << std::endl;
    }
}


int main() {
    std::list<std::string> * names = readFromFileToList<std::string>("names.txt");
    std::list<std::string> * lastNames = readFromFileToList<std::string>("lastNames.txt");
    //cretate teams

    printList(*names);
    std::cout << "Hello, World!" << std::endl;
    Fan* fan = new Fan("michal","kapusta",22,"broklyn","whoaa");
    Player* player = new Player("kacper","nowicki",22,"broklyn",11);
    Human& h = *fan;
    std::cout<<*(Human*)player;
    return 0;
}
