//
// Created by victo on 16/10/2023.
//

#include "lifegame.h"
#define MAX_ROWS 100
#define MAX_COLS 100



int num_neighbors(int x, int y, int tableau[100][100]){ //prendre en compte les espaces extérieurs au tableau = 0
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