#ifndef DEVIS_H
# define DEVIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_BUFF_SIZE 1000

// utils.c
void    cleanFgets(char *str);

// informations.c
int		getTaches(void);
void	getInformations(void);
void	recordElementsFactures(void);

#endif