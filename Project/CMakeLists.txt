cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp Models/Human.cpp Models/Human.hpp Models/Player.cpp Models/Player.hpp Models/Attacker.cpp Models/Attacker.hpp Models/Defender.cpp Models/Defender.hpp Models/GoalKeeper.cpp Models/GoalKeeper.hpp Models/Fan.cpp Models/Fan.hpp Models/Stadium.cpp Models/Stadium.hpp Models/Team.cpp Models/Team.hpp)