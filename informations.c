#include "devis.h"

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


