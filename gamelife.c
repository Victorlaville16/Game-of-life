//
// Created by victo on 16/10/2023.
//
#include "gamelife.h"
#include <stdio.h>

void next_generation(int world[MAX_ROWS][MAX_COLS]){
    int next_generation[MAX_ROWS][MAX_COLS]={0};
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            next_generation[i][j] = get_next_state(i,j, world, world[i][j]);
        }

    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            world[i][j] = next_generation[i][j];

        }

    }
}

int get_next_state(int x, int y, int tableau[MAX_ROWS][MAX_COLS], int actualState){
    int numVoisins = num_neighbors(x, y, tableau);
    if(actualState==0){
        if(numVoisins==3){
            return 1;
        }else
            return 0;
    }else {
        if (numVoisins < 2 || numVoisins > 3) {
            ///Solitude and overcrowding
            return 0;
        } else if (numVoisins == 2 || numVoisins == 3) {
            return 1;
        } else
            return 0;
    }
}


int num_neighbors(int x, int y, int tableau[MAX_ROWS][MAX_COLS]){ //prendre en compte les espaces extérieurs au tableau = 0
    int cellule = tableau[x][y];
    int nbCellulesVivantes=0;

    /*  if(((x-1)>-1)&&(y-1)>-1){
          if (tableau[x-1][y-1]==1){
              nbCellulesVivantes++;
          }

      }*/
    if((y-1)>-1){ // case sur la ligne du dessus
        if((x-1)>-1){ //case en haut a gauche
            if (tableau[x-1][y-1]==1){
                nbCellulesVivantes++;
            }
        }
        if (tableau[x][y-1]==1){ //case au dessus au milieu
            nbCellulesVivantes++;
        }
        if((x+1)<MAX_COLS){ // case au dessus a droite
            if(tableau[x+1][y-1]==1){
                nbCellulesVivantes++;
            }
        }
    }

    if ((x-1)>-1){ // case a gauche
        if(tableau[x-1][y]==1){
            nbCellulesVivantes++;
        }
    }

    if((x+1)<MAX_COLS){// case a droite
        if(tableau[x+1][y]==1){
            nbCellulesVivantes++;
        }
    }

    if((y+1)<MAX_ROWS){ // case en dessous
        if ((x-1)>-1){ // case en dessous a gauche
            if (tableau[x-1][y+1]==1){
                nbCellulesVivantes++;
            }
        }
        if (tableau[x][y+1]==1){ //case en dessous au milieu
            nbCellulesVivantes++;
        }
        if((x+1)<MAX_ROWS){ // case en dessous a droite
            if (tableau[x+1][y+1]==1){
                nbCellulesVivantes++;
            }
        }
    }
    return nbCellulesVivantes;
}

