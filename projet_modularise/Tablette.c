#include "Tablette.h"

#include <stdio.h>
#include <stdlib.h>

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
