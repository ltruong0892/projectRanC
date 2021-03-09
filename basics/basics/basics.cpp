// basics.cpp�: d�finit le point d'entr�e pour l'application console.
//

/*
Ci-dessous, ce sont des directives de pr�processeur.
Ces lignes permettent d'ajouter des fichiers au projet,
fichiers que l'on appelle biblioth�ques.
Gr�ce � ces biblioth�ques, on disposera de fonctions toutes pr�tes pour afficher
par exemple un message � l'�cran.
*/

#include "stdafx.h" // " " -> r�pertoire local
#include <stdio.h> // < > -> biblioth�que du r�pertoire de l'IDE
#include <stdlib.h>
#include <math.h>



// Prototypes des fonctions du code
void test_boucle();
int addition(int nbr1, int nbr2);
double division(int nbr1, int nbr2);
int triple(int nombre);
int incrementeur();
void triplePointeur(int* pointeurSurNombre);
void decoupeMinutes(int *h, int *m);
void affiche(int* tableau, int tailleTableau);
void tableaux();
int sommeTableau(int tableau[], int tailleTableau);

// Variable global (d�conseill�)
int globalTest = 0;

/*
Ci-dessous, vous avez la fonction principale du programme, appel�e main.
C'est par cette fonction que tous les programmes commencent.
Ici, ma fonction se contente d'afficher Bonjour � l'�cran.
*/

int main(int argc, char *argv[])
{
	printf("Hello World !\n");

	int nbr1 = 5, nbr2 = 3;
	int resultat1, resultat3;
	double resultat2;
	resultat1 = addition(nbr1, nbr2);
	resultat2 = division(nbr1, nbr2);
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

	int resultat4 = 0;
	resultat4 = triple(nbr1);
	printf("%d * 3 = %d\n", nbr1, resultat4);

	test_boucle();

	int* monPointeur = NULL;
	int age = 10;
	int* pointeurSurAge; // je cr�e un pointeur
	pointeurSurAge = &age; // pointeurSurAge contient l'adresse de age
	printf("%p\n", pointeurSurAge); // on regarde la valeur de pointeurSurAge donc l'adresse de age
	printf("%d\n", *pointeurSurAge); // on regarde la valeur de la variable � l'adresse pointeurSurAge

	triplePointeur(&age); // on envoie l'adresse de age � la fonction
	printf("\nage apres triplePointeur : %d \n", age); // on affiche la variable age, la fonction a directement modifi� la valeur de la variable car elle connait sont adresse
	/* version alternative
	* int age = 10;
	* int *pointeur = &age;
	* triplePointeur(pointeur);
	* printf("%d", *pointeur);
	*/

	int heures = 0, minutes = 90;

	// on envoie l'adresse de heures et minutes
	decoupeMinutes(&heures, &minutes);

	// Cette fois les valeurs ont �t� modifi�es
	printf("%d heures et %d minutes\n", heures, minutes);

	tableaux();

	return 0;
}


int addition(int nbr1, int nbr2)
{
	return nbr1 + nbr2;
}

double division(int nbr1, int nbr2)
{
	return nbr1 / nbr2;
}

void test_boucle()
{
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
		printf("C'est pas bient�t fini la crise de l'adolescence\n");
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
		printf("Votre choix n'est pas reconnu par notre syst�me, tant pis pour vous\n");
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
	for (compteur = 0; compteur < 5; compteur++)
	{
		printf("Salut les Zeros\n");
	}

}

int triple(int nombre)
{
	int resultat = 0;
	resultat = 3 * nombre;

	return resultat;
}

int incrementeur()
{
	static int nombre = 0; // La variable nombre est cr��e la premi�re fois que la fonction est appel�e

	nombre++;
	return nombre;
} // La variable nombre n'est PAS supprim�e lorsque la fonction est termin�e.

void triplePointeur(int* pointeurSurNombre)
{
	*pointeurSurNombre *= 3; // on multiplie la valeur par 3
}

void decoupeMinutes(int *h, int *m)
{
	/* Attention � ne pas oublier de mettre une �toile devant le nom
	des pointeurs ! Comme �a, vous pouvez modifier la valeur des variables,
	et non leur adresse ! Vous ne voudriez pas diviser des adresses,
	n'est-ce pas ?) */
	*h = *m / 60;
	*m = *m % 60;
}


void tableaux()
{
	int tableau[4] = { 10,20,30,40 }; // tableau initialis� avec des 0
	int tableau2[5] = { 10,20 }; // on initialise les deux 1eres cases et les autres sont automatiquement mises � 0
	int tableau3[4] = { 0 }; // tout est initialis� � 0
	
	// acc�s par les indices
	tableau[0] = 10;
	tableau[1] = 23;
	tableau[2] = 505;
	tableau[3] = 8;

	// "tableau" c'est en fait un pointeur vers la 1ere case, donc on peut utiliser les pointeurs pour r�cupere la 1ere valeure
	printf("1ere valeure du tableau : %d\n", *tableau);

	int case2 = tableau[1]; // Renvoie la valeur de la seconde case (la premi�re case �tant 0)
	int case2b = *(tableau + 1); // Identique : renvoie la valeur contenue dans la seconde case

	int sumTab = sommeTableau(tableau, 4);
	printf("somme tu tableau : %d\n", sumTab);

	// tableau � taille dynamique
	int taille = 5;
	//int tableauDyn[taille]; // pas reconnu par tous les compilateurs
}

void affiche(int* tableau, int tailleTableau)
{
	// Parcourir un tableau et l'afficher
	int i;
	for (i = 0; i < tailleTableau; i++)
	{
		printf("%d\n", tableau[i]);
	}
}

int sommeTableau(int tableau[], int tailleTableau) // m�thode alternative pour passer un tableau en argument de fonction
{
	int i;
	int cpt = 0;
	for (i = 0; i < tailleTableau; i++)
	{
		cpt += tableau[i];
	}
	return cpt;
}