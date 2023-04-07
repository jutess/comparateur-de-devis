#include "devis.h"


void    cleanFgets(char *str){
	for (int i  = 0; str[i]; i++){ // supprime le \n
	if (str[i] == '\n')
		str[i] = 0;
}
}