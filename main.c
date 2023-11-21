#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gamelife.h"
#include "graphics.h"
#include <time.h>

SDL_Window* window;
SDL_Renderer* renderer;

typedef struct {
    SDL_Rect rect;
    void (*action)(int*);
} Button;

void generateRandomWorld(int* world) {
    *world = 1;
    printf("Monde genere aleatoirement.\n");
}

void loadWorldFromFile() {
    printf("Monde charge depuis le fichier de configuration.\n");
}

void renderButton(Button* button) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button->rect);

    // Couleur du texte blanc
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &button->rect);
}

void handleButtonClick(SDL_Event* event, Button* button,int* quit,int*world) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (mouseX >= button->rect.x && mouseX <= button->rect.x + BUTTON_WIDTH &&
            mouseY >= button->rect.y && mouseY <= button->rect.y + BUTTON_HEIGHT) {
            button->action(world);
            *quit = 1;
        }
    }
}


int SDL_main(int argc, char *argv[]) {
    // Déclarez le tableau à deux dimensions et d'autres variables
    int world[MAX_ROWS][MAX_COLS] = {0};
    int lignes, colonnes;
    int nb_generations=0;
    int pause = 0;
    char world_configuration[] = "../World_configuration.txt";
    int choice = -1;
    srand(time(NULL));
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

        SDL_Init(SDL_INIT_VIDEO);

        window = SDL_CreateWindow("SDL Buttons Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        Button generateButton = {{50, 50, BUTTON_WIDTH, BUTTON_HEIGHT}, generateRandomWorld};
        Button loadButton = {{50, 150, BUTTON_WIDTH, BUTTON_HEIGHT}, loadWorldFromFile};

        int quit = 0;
        int* pointeur = &quit;
        SDL_Event event;

        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = 1;
                }

                handleButtonClick(&event, &generateButton,pointeur,&choice);
                handleButtonClick(&event, &loadButton,pointeur,&choice);
            }

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);

            renderButton(&generateButton);
            renderButton(&loadButton);

            SDL_RenderPresent(renderer);
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
        if (choice == 1){
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    world[i][j] = rand() % 2;
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////Création de la page//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Initialisation de la page via SDL
        SDL_Init(SDL_INIT_VIDEO);

        SDL_Window* window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAX_COLS * CELL_SIZE, MAX_ROWS * CELL_SIZE, 0);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        quit = 0;

        while(!quit){
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT) {
                quit = 1;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    pause =  pause^1;
                }
            }
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
            if (!pause){
                next_generation(world);
                nb_generations++;
            }
        }
        // Nettoyez et quittez SDL à la fin
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    FILE* fichier2 = fopen(world_configuration, "w");

    if (fichier2 == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s pour écriture.\n", world_configuration);
        return 1;
    }

    // Écriture des dimensions du tableau
    fprintf(fichier2, "%d %d\n", MAX_ROWS, MAX_COLS);

    // Écriture des états des cellules
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fprintf(fichier2, "%d ", world[i][j]);
        }
        fprintf(fichier2, "\n");
    }

    // Fermeture du fichier
    fclose(fichier2);

    printf("Monde sauvegardé dans le fichier de configuration.\n");
    return 0;
}
