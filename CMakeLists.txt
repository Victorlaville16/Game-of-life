cmake_minimum_required(VERSION 3.21)
project(Game_of_life C)

set(CMAKE_C_STANDARD 99)

# Trouver le module SDL2
find_package(SDL2 REQUIRED)

# Inclure le répertoire des en-têtes de SDL2
include_directories(/mingw64/include/SDL2)

add_executable(Game-of-life main.c gamelife.c gamelife.h
        graphics.c
        graphics.h)

# Lier les bibliothèques de SDL2
target_link_libraries(Game-of-life mingw32 SDL2main SDL2)