//
// Created by victo on 16/10/2023.
//

#ifndef GAME_OF_LIFE_LIFEGAME_H
#define GAME_OF_LIFE_LIFEGAME_H

#define MAX_ROWS 10
#define MAX_COLS 10

void next_generation(int world[MAX_ROWS][MAX_COLS]);
void finalize_evolution();
int get_next_state(int x, int y, int tableau[MAX_ROWS][MAX_COLS], int actualState);
int num_neighbors(int x, int y, int tableau[MAX_ROWS][MAX_COLS]);

#endif //GAME_OF_LIFE_LIFEGAME_H
