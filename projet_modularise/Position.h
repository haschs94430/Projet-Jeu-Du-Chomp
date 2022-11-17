#ifndef __POS__
#define __POS__

#include "Tablette.h"
#define N 8
#define M 16
#define COORD_PR_CASE 150
#define TAILLE_CASE 25

/*type énuméré joueur qui permet de modéliser les 2 joueurs*/

typedef enum joueurs{
	j1,
	j2
}Joueur;

/*type position qui permet de representer une position de jeu*/

typedef struct position{
	Tablette t;
	Joueur actuel;
}Position;

/* On utilise Position *pos pour savoir si la case empoisonnée existe encore ou non
 * et pour définir quel joueur à gagné */ 
int est_jeu_termine(Position *pos, Joueur *joueur_gagnant);

/* Affiche la tablette de chocolat ainsi que le joueur qui est entrain de jouer grâce au information de *pos */
void affiche_position(Position *pos);

#endif
