#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gamelife.h"

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
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
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                if(world[i][j]==0){
                    printf(" ");
                }else
                    printf("*");


            }
            printf("\n");
        }

        /**
         * Faire une boucle infinie pour appeler next_generation()
         * Avoir une fonction sleep de quelques secondes
         * **/
        do {
            printf("\n\n\n\n");
            next_generation(world);
            // Afficher le tableau
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    if(world[i][j]==0){
                        printf(" ");
                    }else
                        printf("*");
                }
                printf("\n");
            }
            sleep(2);
            nb_generations++;
        }while(nb_generations!=15);
    }
    return 0;
}
