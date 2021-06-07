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
#include <string.h>



// Fichier header
#include "basics.h"

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
	chaineCaract();

	RACONTER_SA_VIE()

	MAJEUR(22)

	//struct Coordonnees point; // cr�ation d'une variable point de type Coordonnees, �criture normale mais un peu long car il faut mettre struct
	Coordonnees point; // cr�ation d'une variable point de type Coordonnees via l'alias Coordonnees

	point.x = 10;
	point.y = 20;

	// initialiser une structure
	Coordonnees point2 = { 0,0 };
	Personne utilisateur = { "","","",0,0 };

	// pointeurs de structure
	Coordonnees *point3a = NULL, *point3b = NULL;
	Coordonnees monPoint;
	initialiserCoordonnees(&monPoint);

	// enum�rations
	Volume_son musique = MOYEN;
	if (musique == MOYEN)
	{
		printf("La musique est a un volume MOYEN \n");
	}




	return 0;
}



// Fonctions
int addition(int nbr1, int nbr2)
{
	return nbr1 + nbr2;
}

double division(int nbr1, int nbr2)
{
	return nbr1 / nbr2;
}

int triple(int nombre)
{
	int resultat = 0;
	resultat = 3 * nombre;

	return resultat;
}

// Boucles it�ratives
void test_boucle()
{
	// boucle if
	int age = 0;
	printf("Quel age avez vous ? ");
	fflush(stdout);
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
	printf("1. Royal Deluxe\n2. Mc Deluxe\n3. Mc Bacon\n4.Big Mac\nVotre choix ? ");
	fflush(stdout);
	scanf("%d", &choix);
	switch (choix)
	{
	case 1:
		printf("Vous avez choisi le menu Royal Deluxe\n");
		break;
	case 2:
		printf("Vous avez choisi le menu Mc Deluxe\n");
		break;
	case 3:
		printf("Vous avez choisi le menu Mc Bacon\n");
		break;
	case 4:
		printf("Vous avez choisi le menu Big Mac\n");
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


int incrementeur()
{
	static int nombre = 0; // La variable nombre est cr��e la premi�re fois que la fonction est appel�e

	nombre++;
	return nombre;
} // La variable nombre n'est PAS supprim�e lorsque la fonction est termin�e.


// Pointeurs
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

// Tableaux
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


// Chaines de caract�re
void chaineCaract()
{
	char lettre = 'A';
	printf("%d\n", lettre); // on a le code ascii correspondant
	printf("%c\n", lettre); // affiche la lettre
	char chaine0[6]; // une chaine de caract�re termine tjs par \0 � la fin (signifie la fin de la chaine pour le compilateur) donc il faut faire +1 � la taille
	char chaine[] = "Salut"; // cette �criture ne marche que pour l'initialisation, apr�s il faut faire caract�re par caract�re
	printf("%s\n", chaine);
	demandeNom();
	printf("Faisons une copie\n");
	copieChaine();
	concatChaine();

	int age = 28;
	char chaine1[100];
	// On �crit "Tu as 28 ans" dans chaine
	sprintf(chaine1, "Tu as %d ans !", age);

	// On affiche chaine pour v�rifier qu'elle contient bien cela :
	printf("%s", chaine1);


}

void demandeNom()
{
	char prenom[100]; // on connait pas la taille alors on prend un truc grand
	printf("Comment t'appelles-tu petite Zero ? ");
	fflush(stdout);
	scanf("%s", prenom);
	printf("Salut %s, content de te rencontrer !\n", prenom);

	int longueurChaine = 0;
	// On r�cup�re la longueur du pr�nom et on l'affiche
	longueurChaine = strlen(prenom);
	printf("Votre prenom a %d caracteres !\n", longueurChaine);

	// Chercher un caract�re
	char* suiteChaine = NULL;
	suiteChaine = strchr(prenom, 'V'); // renvoie l'adresse du premier caract�re trouv�
	if (suiteChaine != NULL)
	{
		printf("Et votre prenom contient la lettre V c'est cool !\n");
	}
	else
	{
		printf("Dommage, votre prenom n'a pas la lettre V\n");
	}


}

void copieChaine()
{
	char chaine[] = "Texte";
	char copie[100] = { 0 };
	strcpy(copie, chaine); // on copie "chaine" dans "copie"
	// Si tout s'est bien pass�, la copie devrait �tre identique � chaine
	printf("chaine vaut : %s\n", chaine);
	printf("copie vaut : %s\n", copie);

	// On v�rifie si c'est les m�mes chaines
	if (strcmp(chaine, copie) == 0) // si c'est les m�me chaines
	{
		printf("Les chaines sont identiques.\n");
	}
	else
	{
		printf("Les chaines sont diff�rentes.\n");
	}


}

void concatChaine()
{
	/* On cr�e 2 cha�nes. chaine1 doit �tre assez grande pour accueillir
	le contenu de chaine2 en plus, sinon risque de plantage */
	char chaine1[100] = "Salut ", chaine2[] = "Mateo21";
	strcat(chaine1, chaine2); // On concat�ne chaine2 dans chaine1

	// Si tout s'est bien pass�, chaine1 vaut "Salut Mateo21"
	printf("chaine1 vaut : %s\n", chaine1);
	// chaine2 n'a pas chang� :
	printf("chaine2 vaut toujours : %s\n", chaine2);
}

void chercheChaine()
{
	//// chercher 1er caract�re d'une liste
	char* suiteChaine;
	char test0[] = "Texte de test";
	char test1[] = "xds";
	// On cherche la premi�re occurrence de x, d ou s dans "Texte de test" 
	suiteChaine = strpbrk(test0, test1);
	if (suiteChaine != NULL)
	{
		printf("Voici la fin de la chaine a partir du premier des caracteres trouves : %s", suiteChaine);
	}

	//// chercher une chaine dans une chaine
	char* suiteChaine2;
	
	char test2[] = "test";
	// On cherche la premi�re occurrence de "test" dans "Texte de test" :
	suiteChaine2 = strstr(test0,test2);
	if (suiteChaine2 != NULL)
	{
		printf("Premiere occurrence de test dans Texte de test : %s\n", suiteChaine2);
	}
}

void initialiserCoordonnees(Coordonnees* point)
{
	(*point).x = 0; // �criture un peu longue
	point->y = 0; // version courte avec une fl�che r�serv�e aux pointeurs (. = variable, -> = pointeur)


}
