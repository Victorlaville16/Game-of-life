#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gamelife.h"
#include "graphics.h"

int SDL_main(int argc, char *argv[]) {
    int quit= 0;
    // Déclarez le tableau à deux dimensions et d'autres variables
    int world[MAX_ROWS][MAX_COLS] = {0};
    int lignes, colonnes;
    int nb_generations=0;
    char world_configuration[] = "../World_configuration.txt";

    // Ouvrez le fichier en mode lecture
    FILE *fichier = fopen(world_configuration, "r");

    if (fichier == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", world_configuration);
        return 1;
    }else{
        // Le fichier texte existe
        // Lecture des dimensions du tableau (lignes et colonnes)
        if (fscanf(fichier, "%d %d", &lignes, &colonnes) != 2) {
            fprintf(stderr, "Erreur de lecture des dimensions du tableau.\n");
            fclose(fichier);
            return 1;
        }

        // Lecture des états des cellules et initialisation du tableau
        for (int i = 0; i < lignes; i++) {
            for (int j = 0; j < colonnes; j++) {
                if (fscanf(fichier, "%d", &world[i][j]) != 1) {
                    fprintf(stderr, "Erreur de lecture des etats du tableau.\n");
                    fclose(fichier);
                    return 1;
                }
            }
        }

        // Fermeture du fichier
        fclose(fichier);

        // Afficher le tableau
        /*for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                if(world[i][j]==0){
                    printf(" ");
                }else
                    printf("*");
            }
            printf("\n");
        }*/

        //Initialisation de la page via SDL
        SDL_Init(SDL_INIT_VIDEO);

        SDL_Window* window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAX_COLS * CELL_SIZE, MAX_ROWS * CELL_SIZE, 0);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        SDL_Event event;

        while(!quit && nb_generations <= 100){
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT) {
                quit = 1;
            } else{}
            // Afficher le tableau
            drawWorld(renderer, world);
            /*for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    if(world[i][j]==0){
                        printf(" ");
                    }else
                        printf("*");
                }
                printf("\n");
            }*/
            SDL_Delay(100);
            next_generation(world);
            nb_generations++;
        }
        // Nettoyez et quittez SDL à la fin
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    return 0;
}
