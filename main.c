#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    // Déclarez le tableau à deux dimensions et d'autres variables
    int tableau[MAX_ROWS][MAX_COLS];
    int lignes, colonnes;
    char world_configuration[] = "World_configuration.txt";

    // Ouvrez le fichier en mode lecture
    FILE *fichier = fopen(world_configuration, "r");

    if (fichier == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", world_configuration);
        return 1;
    }

    // Lecture des dimensions du tableau (lignes et colonnes)
    if (fscanf(fichier, "%d %d", &lignes, &colonnes) != 2) {
        fprintf(stderr, "Erreur de lecture des dimensions du tableau.\n");
        fclose(fichier);
        return 1;
    }

    // Lisez les états des cellules et initialisez le tableau
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (fscanf(fichier, "%d", &tableau[i][j]) != 1) {
                fprintf(stderr, "Erreur de lecture des états du tableau.\n");
                fclose(fichier);
                return 1;
            }
        }
    }

    // Fermez le fichier
    fclose(fichier);

    // Le tableau est maintenant initialisé avec les valeurs du fichier
    // Vous pouvez l'utiliser comme vous le souhaitez

    // Exemple : Afficher le tableau
    printf("Tableau initialisé à partir du fichier :\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }

    return 0;
}
