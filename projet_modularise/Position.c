#include "Position.h"

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

/* On utilise Position *pos pour savoir si la case empoisonnée existe encore ou non
 * et pour définir quel joueur à gagné */ 
int est_jeu_termine(Position *pos, Joueur *joueur_gagnant){
	if(0 == pos->t.tab[0][0]){
		*joueur_gagnant = pos->actuel;
		return 1;
	}
	return 0;
}

/* Affiche la tablette de chocolat ainsi que le joueur qui est entrain de jouer grâce au information de *pos */
void affiche_position(Position *pos){
	int i, j;
	MLV_clear_window(MLV_COLOR_BLACK);
	for(i = 0; i < N; ++i){
		for(j = 0; j < M; ++j){
			if(1 == pos->t.tab[i][j]){
				MLV_draw_rectangle(COORD_PR_CASE - 1 + (TAILLE_CASE * j), COORD_PR_CASE - 1 + (TAILLE_CASE * i), TAILLE_CASE + 2, TAILLE_CASE + 2, MLV_COLOR_BLACK);
				MLV_draw_filled_rectangle(COORD_PR_CASE + (TAILLE_CASE * j), COORD_PR_CASE + (TAILLE_CASE * i), TAILLE_CASE, TAILLE_CASE, MLV_COLOR_CHOCOLATE4);
				if(0 == i && 0 == j)
					MLV_draw_filled_circle(COORD_PR_CASE + TAILLE_CASE / 2, COORD_PR_CASE + TAILLE_CASE / 2, TAILLE_CASE / 2 - 5, MLV_COLOR_DARK_MAGENTA);
			}
		}
	}
	/* La case la plus claire représente le joueur qui est entrain de jouer */
	if(j1 == pos->actuel){
		MLV_draw_text_box(650, 200, 100, 50, "Joueur 1", 1, MLV_COLOR_GREY, MLV_COLOR_DARK_ORANGE, MLV_COLOR_GREY, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
		MLV_draw_text_box(650, 250, 100, 50, "Joueur 2", 1, MLV_COLOR_GREY, MLV_COLOR_DARK_BLUE, MLV_COLOR_GREY40, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	}
	else{
		MLV_draw_text_box(650, 200, 100, 50, "Joueur 1", 1, MLV_COLOR_GREY, MLV_COLOR_DARK_ORANGE, MLV_COLOR_GREY40, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
		MLV_draw_text_box(650, 250, 100, 50, "Joueur 2", 1, MLV_COLOR_GREY, MLV_COLOR_BLUE, MLV_COLOR_GREY, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	}
	MLV_actualise_window();
}
