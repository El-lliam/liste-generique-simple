#ifndef _LST_
#define _LST_

struct lst_t {
	struct lst_elm_t * head;
	struct lst_elm_t * tail;
	int numelm;
};

bool empty_lst(const struct lst_t * L);
/* @brief Construire une liste vide */
struct lst_t * new_lst();
/* @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t * L, char * datum);
/* @brief Ajouter en queue de la liste L la donnee */
void queue(struct lst_t *L, char *datum);
/** @brief Insérer dans la liste L la donnée suivant l'ordre donné par la fonction pointée par ptrFct */
void insert_ordered(struct lst_t * L, char * datum , bool (* ptrFct) ());
/** @brief Consulter la tête de la liste */
 struct lst_elm_t * getHead(struct lst_t * L);
 /* @brief Consulter la queue de la liste*/
 struct lst_elm_t *getTail(struct lst_t *L);
 /* @brief Consulter le nombre d'element de la liste*/
 int getNumelm(struct lst_t *L);
 /* @brief Modifier le nombre d'element d'une liste*/
 int setNumelm(struct lst_t *L, int *numElm);
/* @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t ** ptrL , void (*ptrFct)());
/* @brief Visualiser les elements d'une liste grace a la fontion pointée par ptrFct*/
void view_lst(struct lst_t *L, void (*ptrFct)());
/* @brief */

#endif