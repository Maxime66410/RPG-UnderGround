cmake_minimum_required(VERSION 3.20)
project(RPGUnderGround)

set(CMAKE_CXX_STANDARD 14)

add_executable(RPGUnderGround main.cpp Fonctions/preparation.cpp Header/preparation.h Header Fonctions/navigation.cpp Header/navigation.h Fonctions/heros.cpp Header/heros.h Fonctions/sauvegarder.cpp Header/sauvegarder.h Fonctions/magasin.cpp Header/magasin.h Fonctions/combat.cpp Header/combat.h Fonctions/magie.cpp Header/magie.h Fonctions/force.cpp Header/force.h)
