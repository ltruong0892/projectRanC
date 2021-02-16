// TP1_PlusMoins.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int MAX = 100, MIN = 1;
	int nombreMystere;
	int nombreDuJoueur = 0, nbrEssais = 0;
	
	srand(time(NULL)); // initialise le g�n�rateur de nombre al�atoire (� n'executer qu'une seule fois)

	printf("==== Plus ou Moins ====\n");
	printf("Bonjour et bienvenue dans le jeu Plus ou Moins\n");

	// tirage d'un nombre al�atoire � deviner
	nombreMystere = (rand() % (MAX - MIN + 1)) + MIN; 

	// Boucle de jeu
	do
	{
		// On demande au joueur d'entrer un nombre
		printf("Quel est le nombre ? ");
		scanf("%d", &nombreDuJoueur);
		nbrEssais++;

		// Boucle de v�rification du nombre entr� par le joueur
		if (nombreDuJoueur == nombreMystere)
		{
			printf("Bravo, vous avez trouve le nombre mystere\n");
			printf("Vous avez r�ussi en %d coups, super !\n", nbrEssais);
		}
		else if (nombreDuJoueur < nombreMystere)
		{
			printf("C'est plus !\n");
		}
		else
		{
			printf("C'est moins !\n");
		}
	} while (nombreDuJoueur != nombreMystere);

	return 0;
}

