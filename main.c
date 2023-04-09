#include "devis.h"

//retourne le nombre de devis que l'utilisateur souhaite comparer
int	retNbDevisToComp(void){
	int	nb_devis;

	printf(GRE "Combien de devis souhaitez-vous comparer ? : " WHI);
	if (! scanf("%d", &nb_devis)){
		printf("error scanf retNbDevisToComp\n");
		exit (1);
	}
	getchar();
	if (nb_devis < 2){
		printf(RED"Vous devez comparer au moins 2 devis\n"WHI);
		exit (1);
	}
	return nb_devis;
}

void	recArtisansName(t_devis *devis){
	char	*buff;
	int		nb_devis = devis->nb_devis;

	buff = malloc(sizeof(char) * MAX_BUFF_SIZE);
	for (int i = 0; i < nb_devis; i++){
		printf(GRE "Nom de l'artisan %d : " WHI, i + 1);
		if (! fgets(buff, MAX_BUFF_SIZE, stdin)){
			printf("error fgets recArtisansName\n");
			exit (1);
		}
		else
			cleanFgets(buff);
		devis[i].name_artisan = strdup(buff);
	}
}

void	recordPriceForEveryElement(t_devis *devis){
	int	*tabPriceTaches;

	tabPriceTaches = malloc(sizeof(int) * devis->nbElements);	// alloue la mémoire pour le tableau
	for (int i = 0; i < devis->nbElements; i++){
		printf(GRE "prix pour une unité de %s : " WHI, devis->tabDesignationTaches[i]);
		if (! scanf("%d", &tabPriceTaches[i])){
			printf("error scanf recordPriceElements\n");
			exit (1);
		}
		getchar();
	}
	devis->tabPriceTaches = tabPriceTaches;
}

//enregistre le nombre d'elements factures
void	recordNbElementsFactures(t_devis *devis){
	int	*tabNbElem;

	tabNbElem = malloc(sizeof(int) * devis->nbElements);	// alloue la mémoire pour le tableau
	for (int i = 0; i < devis->nbElements; i++){
		printf(GRE "nombre d'unités facturées pour %s : " WHI, devis->tabDesignationTaches[i]);
		if (! scanf("%d", &tabNbElem[i])){
			printf("error scanf recordNbElementsFactures\n");
			exit (1);
		}
		getchar();
	}
	devis->nbTachesFactures = tabNbElem;
}

void	recordInformationsForEveryDevis(t_devis *devis){
	int	nb_devis = devis->nb_devis;
	int	*tabPriceTaches;
	int	*tabNbElem;

	for (int i = 0; i < nb_devis; i++){
		tabNbElem = malloc(sizeof(int) * devis->nbElements);	
		tabPriceTaches = malloc(sizeof(int) * devis->nbElements);	// alloue la mémoire pour le tableau
			for (int i = 0; i < devis->nbElements; i++){
				printf(PUR "Entrer les informations concernant le devis produit par %s\n" WHI, devis[i].name_artisan);
				recordPriceForEveryElement(&devis[i]);
				recordNbElementsFactures(&devis[i]);
			}
		}	
}

int main(int ac, char **av, char **envp){
	// recuperer le nombre de devis a comparer et cree un tableau de devis
	int nb_devis = retNbDevisToComp();
	t_devis	devis[nb_devis];
// 	enregistre les taches facturees et le nom des artisans
	recordElementsFactures(devis, nb_devis);
	recArtisansName(devis);
//	enregistre pour chaque artisant le prix pour chaque élément et le nombre d'éléments facturés
	recordInformationsForEveryDevis(devis);
	return 0;
}
