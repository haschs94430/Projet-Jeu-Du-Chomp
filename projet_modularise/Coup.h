#ifndef __COUP__
#define __COUP__

#include "Position.h"
#include "Tablette.h"
#define COORD_PR_CASE 150
#define TAILLE_CASE 25

/*type qui permet de modéliser un coup joué*/

typedef struct coup{
	int x;
	int y;
}Coup;

/* On renvoie la valeur de la case du chocolat pour savoir si elle existe ou pas 
 * Position *pos représente la tablette de chocolat et 
 * Coup *coup les coordonnées du clic effectué */
int est_legal(Position *pos, Coup *coup);

/* Cette fonction permet d'effectuer un coup valide et donc de modifier la tablette *pos
 * et le joueur qui joue actuellement */
void joue_coup(Position *pos, Coup *coup);

/* Cette fonction permet de savoir si un clic est effetué sur la tablette ou non
 * et renvoie les coordonnées du coup effectuées */
Coup lit_coup(Position *pos);

#endif
