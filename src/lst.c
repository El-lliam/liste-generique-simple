#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>
#include "lst_elm.h"
#include "lst.h"
#include "outils.h"


struct lst_t * new_lst() {
	/* @note : calloc fonctionne de manière identique à malloc
		et de surcroît met à NULL(0) tous les octets alloués */
	struct lst_t * L;
	L = (struct lst_t *)calloc(1,sizeof(struct lst_t));
	assert(L);
	return L;
}
void del_lst(struct lst_t ** ptrL, void (*ptrFct)()) {
	assert(ptrL && *ptrL);
	struct lst_elm_t *E;
  if((*ptrFct)==NULL)
  {
    struct lst_elm_t *aux;
    aux = E;
    E = (*E).suc;
    del_lst_elm(&aux);
  } 
  else 
  {
    for(E = (*ptrL)->head; E != NULL; )
    {
      struct lst_elm_t *aux;
      aux = E;
      E = (*E).suc;
      (*ptrFct)(aux->datum); //ici la fontion pointée sera del_lst_elm
    }
  }
	free(*ptrL);
	*ptrL = NULL;
}

bool empty_lst(const struct lst_t * L ) {
	assert(L);
	return L->numelm == 0;
}
void cons(struct lst_t * L, char *datum) {
	assert(L);
	struct lst_elm_t *E;
	E = new_lst_elm(datum);
	(*E).suc = (*L).head;
	(*L).head = E;
	if ((*L).numelm == 0)
	{
		L->tail = E;
	}
	(*L).numelm = (*L).numelm + 1;
}
void view_lst(struct lst_t * L, void (*ptrFct)() ) {
	for(struct lst_elm_t * E = L->head; E; E = E->suc) {
		(*ptrFct)(E->datum);
	}
}

void insert_after(struct lst_t *L, char* datum, struct lst_elm_t *place)
{
	assert(L);
	if(place == NULL)
	{
		cons(L, datum);
	}
	else
	{
		struct lst_elm_t * E = new_lst_elm(datum);
		E->suc = place->suc;
		place->suc = E;
		if(place == L->tail)
		{
			L->tail = E;
		}
	L->numelm = L->numelm + 1;
	}
}

void insert_ordered(struct lst_t * L, char * datum , bool (*ptrFct)())
{
  // ptrFct pointera sur la fontion reelcmp 
  bool resBool = (*ptrFct)(datum, L->head->datum);
	if(empty_lst(L) || resBool) {
		cons(L,datum);
	} else if((*ptrFct)(L->tail->datum, datum)) {
		insert_after(L,datum,L->tail);
	} else {
    struct lst_elm_t *i, *place;
    i = L->head;
    while((*ptrFct)(datum, i->datum))
    {
      place = i;
      i = i->suc;
    }
		insert_after(L,datum,place);
	}
}
//Le but est de modifier les fonctions de ce que les 
// transtypations se fassent automatiquement
struct lst_elm_t * getHead(struct lst_t * L)
{
  return L->head;
}

struct lst_elm_t * getTail(struct lst_t * L)
{
  return L->tail;
}
int getNumelm(struct lst_t *L)
{
  return L->numelm;
}
/*void listhomoreelle()
{
  struct lst_t *L  = new_lst();
  double *v;
  do 
  {
    double u;
    printf("Entrez un reel (0 pour s'arreter): ");
    scanf("%lf", &u);
    if (u == 0) break;
    v  = (double *)calloc(1, sizeof(double));
    *v = u;
    insert_ordered(L, v, &reelcmp);
    }while(true);
    view_lst(L, &printDouble);
    del_lst(&L, &rmDouble);
}
void listhomoentier()
{
  struct lst_t *L  = new_lst();
  int *v;
  do 
  {
    int u;
    printf("Entrez un entier (0 pour s'arreter): ");
    scanf("%d", &u);
    if (u == 0) break;
    v  = (int *)calloc(1, sizeof(int));
    *v = u;
    insert_ordered(L, v, &reelcmp);
    }while(true);
    view_lst(L, &printInteger);
    del_lst(&L, &rmInteger);
}*/