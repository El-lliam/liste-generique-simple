#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>
#include "lst_elm.h"

struct lst_elm_t * new_lst_elm(char *value)
{
	 struct lst_elm_t *E;
	 E = (struct lst_elm_t*)calloc(1, sizeof(struct lst_elm_t));
	 (*E).datum = value;
	 return E;
}
void del_lst_elm(struct lst_elm_t ** ptrE)
{
	assert(ptrE && *ptrE);
	free(*ptrE);
	*ptrE = NULL;
}
char *getDatum( struct lst_elm_t * E )
{
	assert(E);
	return E->datum;
}
struct lst_elm_t * getSuc ( struct lst_elm_t * E )
{
	assert(E);
	return (*E).suc;

}
void setDatum (struct lst_elm_t * E, char *v )
{
	assert(E);
	E->datum = v;
}
void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S )
{
	assert(E);
	(*E).suc = S;
}