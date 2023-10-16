# Game-of-life

## Règles
- Une cellule vivante meurt si elle a moins de 2 voisins vivants -> Cas de la solitude
- Une cellule vivante meurt si elle a plus de 3 voisins en vie -> Cas de overcrowding
- Une cellule vivante survit si elle a exactement 2 ou 3 voisins vivants
- Une cellule morte devient vivante si elle a exactement 3 voisins vivants
- Les voisins "hors map" d'une cellule en bord de map sont considérés comme morts

  ## Commandes
  - Compilation : gcc -g -O0 -Wall lab1a.c lifegame.c -o lab1a.o

  ## Fonctions
  - Main : Initialiser le monde de Game of life -> Call next_generation()
  - next_generation : Call pour chaque nouvelle génération, établit l'état de chaque cellule de la prochaine génération selon les règles
     Call finalize_evolution() une fois les état tous établis -> Call get_next_state(x,y)
  - finalize_evolution : Set l'état actuel du monde à la next génération et reset l'état de la next génération
  - get_next_state(x,y) : Retourne l'état suivant de la cellule présente aux coordonnées -> Call num_neighbors(x,y)
  - num_neighbors(x,y) : Retourne le nombre de voisins vivants. Les cellules hors limite sont considérées mortes.
