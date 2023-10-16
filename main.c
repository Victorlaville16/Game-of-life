#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    // Déclarez le tableau à deux dimensions et d'autres variables
    int lignes, colonnes;
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
        int world[lignes][colonnes];
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
        printf("Tableau initialise a partir du fichier :\n");
        for (int i = 0; i < lignes; i++) {
            for (int j = 0; j < colonnes; j++) {
                printf("%d ", world[i][j]);
            }
            printf("\n");
        }
    }







    return 0;
}
