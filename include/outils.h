#ifndef _OUTILS_
#define _OUTILS_
#define NB_CHAR 5

void printInteger(int *i);
//@brief Supprime un entier
void rmInteger(int *i);
//@brief Compare deux entiers
bool intcmp(int *i, int *j);
//@brief Affiche un reel
void printDouble(double *d);
//@brief Supprime un reel
void rmDouble(double *d);
//@brief Compare deux reels
bool reelcmp(double *u, double *v);

//  TRAVAUX PERSONNELS
void listhomoreelle();
void listhomoentier();
/**
	* ALGORITHME (FONCTION PRINCIPALE)
	**/
#endif