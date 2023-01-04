#include <iostream>
#include <list>
#include <fstream>
#include "Models/Team.hpp"

template<int N>
inline void loop(int *data) {
    if (data[0] > data[1]) std::swap(data[0], data[1]);
    loop<N - 1>(++data);
}

template<>
inline void loop<0>(int *data) {};

template<int N>
inline void bubble_sort_template(int *data) {
    loop<N - 1>(data);
    bubble_sort_template<N - 1>(data);
}

template<>
inline void bubble_sort_template<2>(int *data) {
    loop<1>(data);
};

template<typename T>
std::list<T> *readFromFileToList(std::string fileName) {
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
void printList(std::list<T> const &list) {
    for (auto const &i: list) {
        std::cout << i << std::endl;
    }
}

template<typename T, int n>
void printArray(int *array) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
}

template<typename T, int n>
std::list<T> *createSubList(std::list<T> *list) {
    auto *result = new std::list<T>;
    int k = 0;
    auto iter = list->begin();
    for (int i = 0; i < n; i++) {
        result->push_back(*iter);
        list->erase(iter++);
    }
    return result;
}


int main() {
    srand(time(nullptr));
    std::list<std::string> *names = readFromFileToList<std::string>("names.txt");
    std::list<std::string> *lastNames = readFromFileToList<std::string>("last_names.txt");
    //cretate names for teams
    std::list<std::string> *namesOfFirstTeam = createSubList<std::string, 11>(names);
    std::list<std::string> *namesOfSecondTeam = createSubList<std::string, 11>(names);
    std::list<std::string> *lastNamesOfFirstTeam = createSubList<std::string, 11>(lastNames);
    std::list<std::string> *lastNamesOfSecondTeam = createSubList<std::string, 11>(lastNames);

    std::list<std::string> *namesOfFansFirstTeam = createSubList<std::string, 10>(names);
    std::list<std::string> *namesOfFansSecondTeam = createSubList<std::string, 10>(names);
    std::list<std::string> *lastNamesOfFansFirstTeam = createSubList<std::string, 10>(lastNames);
    std::list<std::string> *lastNamesOfFansSecondTeam = createSubList<std::string, 10>(lastNames);

    //create teams
    Team *team1 = new Team(namesOfFirstTeam, lastNamesOfFirstTeam, namesOfFansFirstTeam, lastNamesOfFansFirstTeam,
                           "Barcelona");
    Team *team2 = new Team(namesOfSecondTeam, lastNamesOfSecondTeam, namesOfFansSecondTeam, lastNamesOfFansSecondTeam,
                           "Real");
    std::cout << "\nWelcome to football App please select an option:\n";
    std::string mainScreenMessage = "\n T1- Display team 1\n T2 - Display team 2\n P1- penalty shoot for team 1 \n P2- penalty shoot for team 2\n A- play short action\n R- Display result\n S- Display teams potential\n E- Exit\n";
    std::string command;
    while (true) {

        std::cout << mainScreenMessage;
        std::cin >> command;

        if (command == "T1") {
            team1->PrintTeam();
        } else if (command == "T2") {
            team2->PrintTeam();
        } else if (command == "P1") {
            team1->ShotAPenalty(team2);

        } else if (command == "P2") {
            team2->ShotAPenalty(team1);
        } else if (command == "R") {
            std::cout << team1->GetName() << " : " << team2->GetName() << '\n';
            std::cout << team1->GetScore() << " : " << team2->GetScore() << '\n';

        } else if (command == "A") {
            int teamNumber = rand() % (6 - 0 + 1) + 0;
            if (teamNumber == 0) {
                team1->MakeShortAction(team2);
            } else {
                team2->MakeShortAction(team1);
            }
        } else if (command == "S") {
            auto team1p = team1->GetTeamPowerStats();
            auto team2p = team2->GetTeamPowerStats();
            bubble_sort_template<11>(team1p);
            bubble_sort_template<11>(team2p);
            printArray<int, 11>(team1p);
            printArray<int, 11>(team2p);


        } else if (command == "E") {
            delete team1;
            delete team2;

            delete names;
            delete lastNames;

            delete namesOfFirstTeam;
            delete namesOfSecondTeam;
            delete lastNamesOfFirstTeam;
            delete lastNamesOfSecondTeam;

            delete namesOfFansFirstTeam;
            delete namesOfFansSecondTeam;
            delete lastNamesOfFansFirstTeam;
            delete lastNamesOfFansSecondTeam;

            return 0;
        } else {
            std::cout << "Unknown Command\n";
        }
    }
}
