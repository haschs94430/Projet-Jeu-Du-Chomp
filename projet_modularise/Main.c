#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#include "Coup.h"
#include "Position.h"
#include "Tablette.h"


int main(){
	Position jeu;
	Coup c;
	Joueur joueur_gagnant;
	
	jeu.t = cree_tablette();
	jeu.actuel = j1;
	
	MLV_create_window("Chomp", "Tablette", 800, 500);
	
	do{
		affiche_position(&jeu);
		c = lit_coup(&jeu);
		joue_coup(&jeu, &c);
	}while(0 == est_jeu_termine(&jeu, &joueur_gagnant));
	
	MLV_clear_window(MLV_COLOR_BLACK);

	if(j1 == joueur_gagnant)
		MLV_draw_text_box(325, 225, 150, 50, "Le gagnant est \nle joueur 1", 1, MLV_COLOR_GREY, MLV_COLOR_RED, MLV_COLOR_GREY, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	else
		MLV_draw_text_box(325, 225, 150, 50, "Le gagnant est \nle joueur 2", 1, MLV_COLOR_GREY, MLV_COLOR_RED, MLV_COLOR_GREY, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	
	MLV_actualise_window();
	
	MLV_wait_mouse_or_seconds(NULL, NULL, 10);
	
	MLV_free_window();
	
	return 1;
}
