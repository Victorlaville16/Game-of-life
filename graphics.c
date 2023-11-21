//
// Created by User on 19/11/2023.
//

#include "graphics.h"


void drawWorld(SDL_Renderer* renderer, int world[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            SDL_Rect cellRect = {j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE};

            if (world[i][j] == 1) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanc pour une cellule vivante
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Noir pour une cellule morte
            }

            SDL_RenderFillRect(renderer, &cellRect);
        }
    }

    SDL_RenderPresent(renderer);
}
