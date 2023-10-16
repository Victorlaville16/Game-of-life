//
// Created by victo on 16/10/2023.
//

#ifndef GAME_OF_LIFE_LIFEGAME_H
#define GAME_OF_LIFE_LIFEGAME_H

void next_generation();
void finalize_evolution();
int get_next_state(int x, int y);
int num_neighbors(int x, int y, int tableau[100][100]);

#endif //GAME_OF_LIFE_LIFEGAME_H
