#include "devis.h"

void	recordElementsFactures(t_devis *devis, int nb_devis){
	char	**tabDesignationTaches;
	char	buff[500];
	int		i_devis = 0;		
	int		i = 0;
	
	// initialise le tableau de taches à NULL
	tabDesignationTaches = malloc(sizeof(char *) * MAX_BUFF_SIZE);
	for (int i = 0; i < MAX_BUFF_SIZE; i++)
		tabDesignationTaches[i] = NULL;
	printf("%s\n", ASK_TACHES_FACTUREES);
	while (++i){
		memset(buff, '\0', 500);
		printf(GRE"tache %d : " WHI, i);
		if (! fgets(buff, MAX_BUFF_SIZE, stdin)){	// utilise fgets pour lire une ligne entière
				printf("error fgets getTaches\n"); 
				exit (1);
			}
		else
		cleanFgets(buff);
		if ((strcmp(buff, "fin") == 0))
			break;
		tabDesignationTaches[i - 1] = strdup(buff);
	}
	devis->nb_devis = nb_devis;
	devis->nbElements = i - 1;
	devis->tabDesignationTaches = tabDesignationTaches;
	//enregistrer les taches dasn chaque devis et leur nombre
	for (int i = 1; i < nb_devis; i++){
		devis[i].nbElements = devis[0].nbElements;
		devis[i].tabDesignationTaches = devis[0].tabDesignationTaches;
	}	
}


