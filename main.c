#include "devis.h"






void	display(t_devis	*devis){
	printf("--------------Voici les éléments facturés--------------\n");
	for (int i = 0; i < devis->nbElements; i++){
		printf("valeur de i : %d\n", i);
		printf("Elément %d : %s\n", i + 1, devis->tabDesignationTaches[i]);
		printf("Nombre d'éléments facturés : %d\n", devis->nbTachesFactures[i]);
		printf("Prix de l'élément : %d\n", devis->tabPriceTaches[i]);
		printf("Prix total de l'élément : %d\n", devis->tabPriceTaches[i] * devis->nbTachesFactures[i]);
	}
}


int main(int ac, char **av, char **envp){
	t_devis	*devis;
	devis = malloc(sizeof(t_devis));
	// creer un fichier ou on liste toutes les taches. Si ce fichier existe, récupérer les données
	getInformations(devis);
	// afficher un tableau avec le nom des taches, leur prix individuel, leur nombre et le prix total
	display(devis);


	return 0;
}
