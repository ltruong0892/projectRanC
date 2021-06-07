#pragma once

#ifndef DEF_BASICS // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_BASICS // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */


// Structures
struct NomDeVotreStructure
{
    int variable1;
    int variable2;
    int autreVariable;
    double nombreDecimal;
};

typedef struct Coordonnees Coordonnees; // crée un alias de structure
struct Coordonnees
{
    int x;
    int y;
};

typedef struct Personne Personne;
struct Personne
{
    char nom[100];
    char prenom[100];
    char adresse[100];

    int age;
    int genre;
};


// Enumerations (~liste de valeurs possibles pour une variable)
/*
typedef enum Volume Volume;
enum Volume
{
    //FAIBLE, MOYEN, FORT // le compilateur associe une valeur à chaque "mot" (FAIBLE = 0, MOYEN = 1, etc...)
    FAIBLE = 10, MOYEN = 50, FORT = 100
};
*/
enum Volume
{
    //FAIBLE, MOYEN, FORT // le compilateur associe une valeur à chaque "mot" (FAIBLE = 0, MOYEN = 1, etc...)
    FAIBLE = 10, MOYEN = 50, FORT = 100
};
typedef enum Volume Volume_son;



// Prototypes des fonctions
void test_boucle();
int addition(int nbr1, int nbr2);
double division(int nbr1, int nbr2);
int triple(int nombre);
int incrementeur();
void triplePointeur(int* pointeurSurNombre);
void decoupeMinutes(int* h, int* m);
void affiche(int* tableau, int tailleTableau);
void tableaux();
int sommeTableau(int tableau[], int tailleTableau);
void chaineCaract();
void demandeNom();
void copieChaine();
void concatChaine();
void initialiserCoordonnees(Coordonnees *point);

// Constante préprocesseur : va remplacer dans les code une "expression" par une valeur (donc pas pareil que "const int")
#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
#define NOMBRE_PIXELS (LARGEUR_FENETRE * HAUTEUR_FENETRE)
// On peut aussi s'en servir pour fixer la taille des tableaux car pas une variable ni une constante

// Macro
#define RACONTER_SA_VIE()   printf("Coucou, je m'appelle Brice\n"); \
                            printf("J'habite a Nice\n"); \
                            printf("J'aime la glisse\n");

#define MAJEUR(age) if (age >= 18) \
                    printf("Vous etes majeur\n");







#endif
