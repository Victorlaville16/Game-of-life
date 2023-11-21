//
// Created by User on 19/11/2023.
//

#ifndef GAME_OF_LIFE_GRAPHICS_H
#define GAME_OF_LIFE_GRAPHICS_H
#include <SDL2/SDL.h>
#include "gamelife.h"

#define CELL_SIZE 30  // Taille d'une cellule en pixels
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50


void drawWorld(SDL_Renderer* renderer,int world[MAX_ROWS][MAX_COLS]);
#endif //GAME_OF_LIFE_GRAPHICS_H
