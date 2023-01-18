#ifndef _ELM_
#define _ELM_
#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>

struct lst_elm_t {
char *datum;
struct lst_elm_t * suc;
};

struct lst_elm_t * new_lst_elm(char * datum);
/* @brief Supprimer un élément de liste et mettre son pointeur à NULL */
void del_lst_elm(struct lst_elm_t ** ptrE);
/* @brief Renvoyer la valeur entière de l'élément */
char* getDatum( struct lst_elm_t * E );
/* @brief Renvoyer le pointeur sur le successeur de l'élément */
struct lst_elm_t * getSuc( struct lst_elm_t * E );
/* @brief Modifier la valeur entière de l'élément */
void setDatum(struct lst_elm_t * E, char *datum );
/* @brief Modifier le pointeur sur le successeur de l'élément */
void setSuc( struct lst_elm_t * E, struct lst_elm_t * S );

#endif