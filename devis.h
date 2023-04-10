#ifndef DEVIS_H
# define DEVIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_BUFF_SIZE 1000
#define	NB_DIFF_TACHES 200

#define PUR "\033[1;35m\033[1m"
#define YEL "\033[1;33m\033[1m"
#define WHI "\033[0m"
#define GRE "\033[1;32m\033[1m"
#define RED "\033[1;31m\033[1m"
#define ASK_TACHES_FACTUREES PUR "Dans vos devis,plusieurs taches identiques sont facturées.\nVeuillez enregistrer la liste des taches communes à comparer.\n" YEL "Rentrer 'fin' dans le terminal lorsque la liste des taches est terminée\n" WHI


typedef struct	s_devis
{
    char	**tabTaches; //tableau avec les noms des taches
    int     *nbTachesFactures;      //  tableau avec nombre de fois ou chaque tache a été facturée
    int		*tabPriceTaches;        // tableau avec le prix de chaque tache
    int     nbElements;             // nombre de taches différentes
    int     nb_devis;               // nombre de devis à comparer
    int     costDevis;
    int     *FinalCostForEveryTaches;
    char    *name_artisan;
}				t_devis;

// utils.c
void    cleanFgets(char *str);

// informations.c
// enregistre la liste des taches facturee
void    recordElementsFactures(t_devis *devis, int nb_devis);
//retourne le nombre de devis que l'utilisateur souhaite comparer
int	retNbDevisToComp(void);
// enregistre le nom des artisans
void	recArtisansName(t_devis *devis);
// enregistre le prix unitaire de chaque element
void	recordPriceForEveryElement(t_devis *devis);
//enregistre le nombre d'elements factures
void	recordNbElementsFactures(t_devis *devis);
// enregistre les informations détaillées du devis
void	recordDevisInform(t_devis *devis);
// enregistre le cout total de chaque element et le cout total du devis
void	recordAllcosts(t_devis *devis);
	// affiche chaque devis avec le prix unitaire de chaque élément et le nombre d'éléments facturés
void	dispDevisInformations(t_devis *devis);



#endif