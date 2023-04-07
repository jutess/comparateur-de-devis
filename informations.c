#include "devis.h"

int	getTaches(void){
	char buff[MAX_BUFF_SIZE];
	memset(buff, 0, MAX_BUFF_SIZE);		// initialise chaque octet à 0
	printf("pour comparer les devis, votre artisan a tarifé une série de taches.\n");
	printf("Si vous disposez de ce fichier, dites 'oui'. Si ce n'est pas le cas, dites 'non'.\n");
	while ((strcmp(buff, "oui") != 0) && (strcmp(buff, "non") != 0)){	// boucle tant qu'il n'y a pas oui ou non
		if ((strcmp(buff, "oui") != 0) && (strcmp(buff, "non") != 0)){
			printf("Votre réponse : ");
			if (! fgets(buff, MAX_BUFF_SIZE, stdin)){
				printf("error fgets getTaches\n"); // utilise fgets pour lire une ligne entière
				exit (1);
			}
			cleanFgets(buff);
		}
		else
			break;
	}
	if ((strcmp(buff, "non") == 0))
		return (0);
	return (1);
}

void	recordElementsFactures(void){
	char	**tabElem;
	char	buff[500];
	int		i = 0;
	
	tabElem = malloc(sizeof(char *) * MAX_BUFF_SIZE);
	for (int i = 0; i < MAX_BUFF_SIZE; i++)
		tabElem[i] = NULL;
	while (1 && ++i){
		printf("Entrez l'élément %d facturé (si tous les éléments on été enregistrés, tapez 'fin')\n", i);
		printf("Elément %d : ", i);
		if (! fgets(buff, MAX_BUFF_SIZE, stdin)){
				printf("error fgets getTaches\n"); // utilise fgets pour lire une ligne entière
				exit (1);
			}
			cleanFgets(buff);
		if ((strcmp(buff, "fin") == 0))
			break;
		tabElem[i - 1] = strdup(buff);
	}
	for (int i = 0; tabElem[i]; i++)
		printf("%s\n", tabElem[i]);
}


void	getInformations(void){
	if (getTaches())
		printf("le ficher existe\n"); // lancer fonction de récupération des éléments facturés
	else{                               // le ficher n'existe pas	
		printf("le ficher n'existe pas\n"); // lancer fonction pour enregibuffer toutes les éléments facturés
		recordElementsFactures();
	}	
}