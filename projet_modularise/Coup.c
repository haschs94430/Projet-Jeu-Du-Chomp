#include "Coup.h"

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

/* On renvoie la valeur de la case du chocolat pour savoir si elle existe ou pas 
 * Position *pos représente la tablette de chocolat et 
 * Coup *coup les coordonnées du clic effectué */
int est_legal(Position *pos, Coup *coup){
	return pos->t.tab[coup->x][coup->y];
}

/* Cette fonction permet d'effectuer un coup valide et donc de modifier la tablette *pos
 * et le joueur qui joue actuellement */
void joue_coup(Position *pos, Coup *coup){
	mange(&(pos->t), coup->x, coup->y);
	if(j1 == pos->actuel)
		pos->actuel = j2;
	else
		pos->actuel = j1;
}

/* Cette fonction permet de savoir si un clic est effetué sur la tablette ou non
 * et renvoie les coordonnées du coup effectuées */
Coup lit_coup(Position *pos){
	int x, y;
	Coup c;
	do{
		MLV_wait_mouse(&y, &x);
		c.x = (x - COORD_PR_CASE) / TAILLE_CASE;
		c.y = (y - COORD_PR_CASE) / TAILLE_CASE;
	}while(((c.x < 0 || c.x > M) && (c.y < 0 || c.y > N)) || 1 != est_legal(pos, &c));
	return c;
}
