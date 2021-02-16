// basics.cpp : définit le point d'entrée pour l'application console.
//

/*
Ci-dessous, ce sont des directives de préprocesseur.
Ces lignes permettent d'ajouter des fichiers au projet,
fichiers que l'on appelle bibliothèques.
Grâce à ces bibliothèques, on disposera de fonctions toutes prêtes pour afficher
par exemple un message à l'écran.
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void testwhile();

/*
Ci-dessous, vous avez la fonction principale du programme, appelée main.
C'est par cette fonction que tous les programmes commencent.
Ici, ma fonction se contente d'afficher Bonjour à l'écran.
*/

int main(int argc, char *argv[])
{
	printf("Hello World !\n");

	int nbr1 = 5, nbr2 = 3;
	int resultat1, resultat3;
	double resultat2;
	resultat1 = nbr1 + nbr2;
	resultat2 = nbr1 / nbr2;
	resultat3 = nbr1 % nbr2;
	printf("Faisons quelques calculs ^^\n");
	printf("%d + %d = %d \n", nbr1, nbr2, resultat1);
	printf("%d / %d = %f \n", nbr1, nbr2, resultat2);
	printf("%d %% %d = %d \n", nbr1, nbr2, resultat3);
	int nbr3 = 0, nbr4 = 10;
	nbr3++;
	nbr4--;
	nbr3 += 4;
	nbr4 *= 2;
	int nbr5 = -27, nbr6 = 52.71;
	double absolu, dessus;
	absolu = fabs(nbr5);
	dessus = ceil(nbr6);

	const int NBR_DE_VIES_INITIALES = 5;

	// boucle if
	int age = 0;
	printf("Quel age avez vous ? ");
	scanf("%d", &age);
	if (age >= 18 && age < 25)
	{
		printf("Ah vous etes majeur mais encore jeune\n");
	}
	else if (age > 12)
	{
		printf("C'est pas bientôt fini la crise de l'adolescence\n");
	}
	else
	{
		printf("on va se calmer gamin !\n");
	}

	// switch case
	int choix = 0;
	printf("=== Menu ===\n");
	printf("1. Royal Deluxe\n2. Mc Deluxe\n3. Mc Bacon\n4.Big Mac\nVotre choix ?");
	scanf("%d", &choix);
	switch (choix)
	{
	case 1:
		printf("Vous avez choisi le menu Royal Deluxe ");
		break;
	case 2:
		printf("Vous avez choisi le menu Mc Deluxe");
		break;
	case 3:
		printf("Vous avez choisi le menu Mc Bacon");
		break;
	case 4:
		printf("Vous avez choisi le menu Big Mac");
		break;
	default:
		printf("Votre choix n'est pas reconnu par notre système, tant pis pour vous\n");
		break;
	}

	// boucle conditionnelle en ternaire
	int autorisation;
	autorisation = (age >= 18) ? 1 : 0;

	// boucle while
	int compteur = 0;

	while (compteur < 10)
	{
		printf("La variable compteur vaut %d\n", compteur);
		compteur++;
	}

	// boucle do while
	compteur = 0;
	do
	{
		printf("Coucou\n");
		compteur++;
	} while (compteur < 5);

	// boucle for
	compteur = 0;
	for (compteur = 0;compteur < 5;compteur++)
	{
		printf("Salut les Zeros\n");
	}


	return 0;
}



