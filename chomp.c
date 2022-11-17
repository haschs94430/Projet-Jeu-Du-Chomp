#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define N 8
#define M 16
#define COORD_PR_CASE 150
#define TAILLE_CASE 25

/*type tablette qui permet de représenter une tablette de chocolat de dimension n*m*/

typedef struct tablette{
	int tab[N][M];
}Tablette;

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

/*type qui permet de modéliser un coup joué*/

typedef struct coup{
	int x;
	int y;
}Coup;

/*cette fonction creer la tablette et met toutes les valeurs du tableau a 1, renvoie la tablette creer*/

Tablette cree_tablette(){
	int i, j;
	Tablette res;
	for(i = 0; i < N; ++i){
		for(j = 0; j < M; ++j){
			res.tab[i][j] = 1;
		}
	}
	return res;
}

/* Cette fonction modifie la tablette *t pour changer les cases valides en cases non-valides après un clic */
void mange(Tablette *t, int x, int y){
	int i, j;
	for(i = x; i < N; ++i){
		for(j = y; j < M; ++j){
			t->tab[i][j] = 0;
		}
	}
}

/* On renvoie la valeur de la case du chocolat pour savoir si elle existe ou pas 
 * Position *pos représente la tablette de chocolat et 
 * Coup *coup les coordonnées du clic effectué */
int est_legal(Position *pos, Coup *coup){
	return pos->t.tab[coup->x][coup->y];
}

/* On utilise Position *pos pour savoir si la case empoisonnée existe encore ou non
 * et pour définir quel joueur à gagné */ 
int est_jeu_termine(Position *pos, Joueur *joueur_gagnant){
	if(0 == pos->t.tab[0][0]){
		*joueur_gagnant = pos->actuel;
		return 1;
	}
	return 0;
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
