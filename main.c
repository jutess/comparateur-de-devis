#include "devis.h"


// affiche les différences de cout en pourcentage pour chaque tache unitaire
void	dispDiffCostForEveryElement(t_devis *devis){
	//parcours chaque tache des devis et les compare entre les devis. affiche la différence de cout en pourcentage
	int i_devis = -1;
	for (int i = 0; i < devis->nbElements; i++){
		printf(RED "----------------------------------------------------------------\n" WHI);
		printf(PUR "tache : %s\n" WHI, devis->tabTaches[i]);
		i_devis = -1;
		while(++i_devis < devis->nb_devis){
			if (i_devis + 1 < devis->nb_devis){
				//la tache est moins chere cjew le premoer artisan
				if (devis[i_devis].tabPriceTaches[i] < devis[i_devis + 1].tabPriceTaches[i]){
					printf(GRE "%s : %d€\n" WHI, devis[i_devis].name_artisan, devis[i_devis].tabPriceTaches[i]);
					printf(RED "%s : %d€\n" WHI, devis[i_devis + 1].name_artisan, devis[i_devis + 1].tabPriceTaches[i]);
					printf(RED "difference de prix : %d%%\n" WHI, (devis[i_devis + 1].tabPriceTaches[i] - devis[i_devis].tabPriceTaches[i]) * 100 / devis[i_devis + 1].tabPriceTaches[i]);
				}
				// la tache est plus chere chez le premier artisan
				else if (devis[i_devis].tabPriceTaches[i] > devis[i_devis + 1].tabPriceTaches[i]){
					printf(GRE "%s : %d€\n" WHI, devis[i_devis].name_artisan, devis[i_devis].tabPriceTaches[i]);
					printf(RED "%s : %d€\n" WHI, devis[i_devis + 1].name_artisan, devis[i_devis + 1].tabPriceTaches[i]);
					printf(RED "difference de prix : %d%%\n" WHI, (devis[i_devis].tabPriceTaches[i] - devis[i_devis + 1].tabPriceTaches[i]) * 100 / devis[i_devis].tabPriceTaches[i]);
				}
				//la tache est au meme prix chez les deux artisans
				else if (devis[i_devis].tabPriceTaches[i] == devis[i_devis + 1].tabPriceTaches[i]){
					printf(GRE "%s : %d€\n" WHI, devis[i_devis].name_artisan, devis[i_devis].tabPriceTaches[i]);
					printf(GRE "%s : %d€\n" WHI, devis[i_devis + 1].name_artisan, devis[i_devis + 1].tabPriceTaches[i]);
					printf(GRE "difference de prix : 0%%\n" WHI);
				}
			}			
		}
		

	}
}

int main(int ac, char **av, char **envp){
	// recuperer le nombre de devis a comparer et cree un tableau de devis
	int nb_devis = retNbDevisToComp();
	t_devis	devis[nb_devis];
// 	enregistre les taches facturee
	recordElementsFactures(devis, nb_devis);
// 	enregistre le nom des artisans
	recArtisansName(devis);
//	enregistre pour chaque artisant le prix pour chaque élément et le nombre d'éléments facturés
	recordDevisInform(devis);
// 	enregistre le pris total de revient de chaque élément et le cout total
	recordAllcosts(devis);
// 	affiche les informations de chaque devis et leur cout total	
	dispDevisInformations(devis);
// affiche les différences de cout en pourcentage pour chaque tache unitaire
	dispDiffCostForEveryElement(devis);

	return (0);
}
