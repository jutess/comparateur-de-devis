#ifndef DEVIS_H
# define DEVIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_BUFF_SIZE 1000

typedef struct	s_devis
{
    char	**tabDesignationTaches; //tableau avec les noms des taches
    int     *nbTachesFactures;      //  tableau avec nombre de fois ou chaque tache a été facturée
    int		*tabPriceTaches;        // tableau avec le prix de chaque tache
    int     nbElements;             // nombre de taches différentes
}				t_devis;

// utils.c
void    cleanFgets(char *str);

// informations.c
int		getTaches(void);
void    getInformations(t_devis *devis);
void    recordPriceElements(t_devis *devis);
void    recordElementsFactures(t_devis *devis);
void    recordNbElementsFactures(t_devis *devis);

#endif