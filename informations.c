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
		printf(GRE "prix pour une unité de %s : " WHI, devis->tabTaches[i]);
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
		printf(GRE "nombre d'unités facturées pour %s : " WHI, devis->tabTaches[i]);
		if (! scanf("%d", &tabNbElem[i])){
			printf("error scanf recordNbElementsFactures\n");
			exit (1);
		}
		getchar();
	}
	devis->nbTachesFactures = tabNbElem;
}

void	recordDevisInform(t_devis *devis){
	for (int i = 0; i < devis->nb_devis; i++){
			printf(PUR "\n----------------------------------------------------------------\n" WHI);
			printf(PUR "Entrer les informations concernant le devis produit par %s\n" WHI, devis[i].name_artisan);
			printf(PUR "----------------------------------------------------------------\n" WHI);
			recordPriceForEveryElement(&devis[i]);
			recordNbElementsFactures(&devis[i]);
	}	
}

void	recordAllcosts(t_devis *devis){
	int *totalCostForEveryElement;
	int	totalCost = 0;

	for(int i = 0; i < devis->nb_devis; i++){
		//calcul le cout total pour chacun des éléments
		totalCost = 0;
		totalCostForEveryElement = malloc(sizeof(int) * devis[i].nbElements);
		for (int j = 0; j < devis[i].nbElements; j++){
			totalCostForEveryElement[j] = devis[i].tabPriceTaches[j] * devis[i].nbTachesFactures[j];
		}
		// calcul le cout total de chaque element
		for (int j = 0; j < devis->nbElements; j++){
			totalCost += devis[i].tabPriceTaches[j] * devis[i].nbTachesFactures[j];
		}
		devis[i].costDevis = totalCost;
	}
}

	// affiche chaque devis avec le prix unitaire de chaque élément et le nombre d'éléments facturés
void	dispDevisInformations(t_devis *devis){
	int nb_devis = devis->nb_devis;
	for (int i = 0; i < nb_devis; i++){
		printf(RED "devis %s\n" WHI, devis[i].name_artisan);
		for (int j = 0; j < devis[i].nbElements; j++){
			printf(GRE "%s : %d€\n" WHI, devis[i].tabTaches[j], devis[i].tabPriceTaches[j]);
			printf(GRE "nombre d'unités facturées : %d\n" WHI, devis[i].nbTachesFactures[j]);
		}
	}
	for (int i = 0; i < nb_devis; i++){
		printf(RED "cout total du devis %s : %d\n" WHI, devis[i].name_artisan, devis[i].costDevis);
	}
}



void	recordElementsFactures(t_devis *devis, int nb_devis){
	char	**tabTaches;
	char	buff[MAX_BUFF_SIZE];
	int		i_devis = 0;		
	int		i = 0;
	
	//malloc le tableau de taches que l'artisan doit réaliser
	tabTaches = malloc(sizeof(char *) * NB_DIFF_TACHES);
	if (!tabTaches){
		printf("error malloc tabTaches\n");
		exit (1);
	}
	// initialise le tableau de taches à NULL
	for (int i = 0; i < NB_DIFF_TACHES; i++)
		tabTaches[i] = NULL;
	printf("%s\n", ASK_TACHES_FACTUREES);
	while (++i){
		memset(buff, '\0', 500);						// nettoie le buffer
		printf(GRE"tache %d : " WHI, i);				// demande a l'utilisateur de rentrer une tache
		if (! fgets(buff, MAX_BUFF_SIZE, stdin)){		// récupère la tache
				printf("error fgets getTaches\n"); 
				exit (1);
			}
		cleanFgets(buff);								// nettoie le \n du buffer
		if ((strcmp(buff, "fin") == 0))					// condition d'arret de la boucle si toutes les taches sont rentrées
			break;
		tabTaches[i - 1] = strdup(buff);				// copie la tache dans le tableau
	}
	devis->nb_devis = nb_devis;
	devis->nbElements = i - 1;
	devis->tabTaches = tabTaches;
	//enregistrer les taches dans chaque devis et leur nombre
	for (int i = 1; i < nb_devis; i++){
		devis[i].nbElements = devis[0].nbElements;
		devis[i].tabTaches = devis[0].tabTaches;
	}	
}


