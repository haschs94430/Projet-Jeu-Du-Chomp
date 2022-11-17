#ifndef __TAB__
#define __TAB__


#define N 8
#define M 16

/*type tablette qui permet de représenter une tablette de chocolat de dimension n*m*/

typedef struct tablette{
	int tab[N][M];
}Tablette;

/*cette fonction creer la tablette et met toutes les valeurs du tableau a 1, renvoie la tablette creer*/

Tablette cree_tablette();

/* Cette fonction modifie la tablette *t pour changer les cases valides en cases non-valides après un clic */
void mange(Tablette *t, int x, int y);

#endif
