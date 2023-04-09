#ifndef DEVIS_H
# define DEVIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_BUFF_SIZE 1000

#define PUR "\033[1;35m\033[1m"
#define YEL "\033[1;33m\033[1m"
#define WHI "\033[0m"
#define GRE "\033[1;32m\033[1m"
#define RED "\033[1;31m\033[1m"
#define ASK_TACHES_FACTUREES PUR "Dans vos devis,plusieurs taches identiques sont facturées.\nVeuillez enregistrer la liste des taches communes à comparer.\n" YEL "Rentrer 'fin' dans le terminal lorsque la liste des taches est terminée\n" WHI


typedef struct	s_devis
{
    char	**tabDesignationTaches; //tableau avec les noms des taches
    int     *nbTachesFactures;      //  tableau avec nombre de fois ou chaque tache a été facturée
    int		*tabPriceTaches;        // tableau avec le prix de chaque tache
    int     nbElements;             // nombre de taches différentes
    int     nb_devis;               // nombre de devis à comparer
    char    *name_artisan;
}				t_devis;

// utils.c
void    cleanFgets(char *str);

// informations.c
void    recordElementsFactures(t_devis *devis, int nb_devis);
void	recordInformationsForEveryDevis(t_devis *devis);
void	recordPriceForEveryElement(t_devis *devis);
void	recordNbElementsFactures(t_devis *devis);



#endif