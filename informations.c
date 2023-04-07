#include "devis.h"

int	getTaches(void){
	char str[50];
	printf("pour comparer les devis, votre artisan a tarifé une série de taches.\n");
	printf("Si vous disposé de ce fichier, dites 'oui'. Si ce n'est pas le cas, dites 'non'.\n");
	printf("Votre réponse : ");
	scanf("%s", str);
	while (1){
		if ((strcmp(str, "oui") != 0) && (strcmp(str, "non") != 0)){
			printf("Votre réponse : ");
			scanf("%s", str);
		}
		else
			break;
	}
	if ((strcmp(str, "non") == 0))
		return (0);
	return (1);
}

void	getInformations(void){
	if (getTaches())
		printf("le ficher existe\n"); 
	else	// le ficher n'existe pas	
		printf("le ficher n'existe pas\n"); 
}