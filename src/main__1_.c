/**
	@note
			Compiler avec : gcc -Wall -std=c11 -o intlist intlist.c
	@brief
		Conception d'un type pour les listes d'entiers et des fonctions associées
	@TODO
		Ajoutez les fonctions de consultation des éléments de liste :
		+ new_lst_elm
		+ del_lst_elm
		+ getX
		+ getSuc
		+ setX
		+ setSuc
		Puis, séparez les éléments afin qu'apparaissent :
		+ Un fichier d'entêtes (.h) de la bibliothèque élément de liste d'entiers,
		+ Un fichier d'entêtes (.h) de la bibliothèque liste d'entiers,
		+ Les fichiers de définitions (.c) correspondant aux déclarations du fichier d'entête
		+ Un fichier main.c ne contenant que la fonction principale.
		Enfin, construisez le Makefile
*/
#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> 
#include "lst_elm.h"
#include "lst.h"
#include "outils.h"
// librairie d'assertions
// Caractere maximal pouvant etre contenu

/**
	* LES TYPES ABSTRAITS
	**/

/* @brief Le type abstrait d'un _élément_ de liste:
 * + x - un entier,
 * + suc - un pointeur sur son successeur (ou NULL s'il n'y en a pas)
 */

/**
	* DÉCLARATION DES FONCTIONS ASSOCIÉES
	**/
/* @brief Créer un élément de liste et y ranger la valeur entière value */



/* @brief Le type abstrait d'une _liste_:
 * + head - le premier élément de la liste
 * + tail - le dernier élément de la liste
 * + numelm - le nombre d'élément dans la liste
 */

/**
	* DÉCLARATION DES FONCTIONS ASSOCIÉES
	**/
/* @brief Vérifier si la liste L est vide ou pas */

//NOUVELLE FONCTIONS SPECIFIQUES AU LISTE SIMPLEMENT CHAINE

int main() 
{
  
  int cmpt;
  char a[NB_CHAR]  , b[NB_CHAR] , c[NB_CHAR] , d[NB_CHAR] ;
  //a[4] = '\0'; b[4] = '\0';
  struct lst_t *L = new_lst();
  struct lst_elm_t *iter;
  printf("Vous allez entrez 4 valeurs suc(Entiere ou réelle\n");
  for (int i = 0; i < 4; i++)
  {
    printf("Entrez la valeur %d: \t", i+1);
    if (i == 0) scanf("%s", a);
    if (i == 1) scanf("%s", b);
    if (i == 2) scanf("%s", c);
    if (i == 3) scanf("%s", d);
  }
  
  cons(L, a);//un entier
  cons(L, b);// un entier
  cons(L, c);//un reel
  cons(L, d);// un reel
  // * La liste vaut [3.14; 5.4; 4; 8 ] *
  /*for(cmpt = 0, iter = getHead(L); cmpt < getNumelm(L); cmpt+= 1, iter = getSuc(iter))
  {
    if(cmpt < 2)
    {
      double *d = (double *) getDatum(iter);
      printf("La valeur est reelle et vaut : %lf\n", *d);
    }
    else 
    {
      int *d = (int *) getDatum(iter);
      printf("La valeur est entiere et vaut : %d\n", *d);
    }
  }*/
  

  //printf("char = %s et flaot = %lf", a, atof(a));
  for(cmpt = 0, iter = getHead(L); cmpt < getNumelm(L); cmpt+= 1, iter = getSuc(iter))
  {
    int i = 0;
    bool isInteger = true;
    char *aux = getDatum(iter);
    while(i < 5 && isInteger)
    {
      if (aux[i] == '.')
      {
        isInteger = false;
      }
      i++;
    }
    if(isInteger == false)
    {
      double d = atof(aux);
      printDouble(&d);
      
    }
    else{
      int i = atoi(aux);
      printInteger(&i);
    }
    //printf("%s  ", aux);
  }
    
  printf("\nMade by NegroDiscret\n");
  
  return 0;
}

/**
	* DÉFINITIONS DES FONCTIONS
	**/
/* @ToDo Créez les fonctions:
 * new_lst_elm, del_lst_elm, getX, getSuc, setX, setSuc
*/
//---------------------





