#include <stdlib.h>
#include <stdio.h>


typedef union {
    int Nombre;
    char Signe;
} TypeValeur;

typedef struct Sommet {
    TypeValeur Valeur;
    struct Sommet* FilsG;
    struct Sommet* FilsD;
} Sommet;

typedef Sommet* Arbre;


Arbre ConstruireFeuille(int valeur) {
    Sommet* feuille = (Sommet*) malloc(sizeof(Sommet));

    feuille->Valeur.Nombre = valeur;

    feuille->FilsD = NULL;
    feuille->FilsG = NULL;

    return feuille;
}


Arbre ConstruireNoeud(char operateur, Arbre gauche, Arbre droit) {
    Sommet* racine = (Sommet*) malloc(sizeof(Sommet));

    racine->Valeur.Signe = operateur;

    racine->FilsD = droit;
    racine->FilsG = gauche;

    return racine;
}


void Infixe(Arbre arbre) {
    if (arbre->FilsG == NULL && arbre->FilsD == NULL) {
        printf("%d", arbre->Valeur.Nombre);
    } else {
        printf("(");
        Infixe(arbre->FilsG);
        printf("%c", arbre->Valeur.Signe);
        Infixe(arbre->FilsD);
        printf(")");
    }
}


void Prefixe(Arbre arbre) {
    if (arbre->FilsG == NULL && arbre->FilsD == NULL) {
        printf("%d ", arbre->Valeur.Nombre);
    } else {
        printf("%c", arbre->Valeur.Signe);
        Prefixe(arbre->FilsG);
        Prefixe(arbre->FilsD);
    }
}


void Postfixe(Arbre arbre) {
    if (arbre->FilsG == NULL && arbre->FilsD == NULL) {
        printf("%d ", arbre->Valeur.Nombre);
    } else {
        Postfixe(arbre->FilsG);
        Postfixe(arbre->FilsD);
        printf("%c", arbre->Valeur.Signe);
    }
}


int Eval(Arbre arbre) {
    if (arbre->FilsG == NULL && arbre->FilsD == NULL) {
        return(arbre->Valeur.Nombre);
    } else {
        switch (arbre->Valeur.Signe)
        {
        case '+':
            return(Eval(arbre->FilsG) + Eval(arbre->FilsD));
        case '-':
            return(Eval(arbre->FilsG) - Eval(arbre->FilsD));
        case '*':
            return(Eval(arbre->FilsG) * Eval(arbre->FilsD));
        case '/':
            return(Eval(arbre->FilsG) / Eval(arbre->FilsD));
        }
    }
}


void DetruireArbre(Arbre arbre) {
    if (arbre->FilsG) {
        DetruireArbre(arbre->FilsG);
    }
    if (arbre->FilsD) {
        DetruireArbre(arbre->FilsD);
    }
    free(arbre);
}



int main() {
    Arbre arbre = ConstruireNoeud(
        '*',
        ConstruireNoeud(
            '+',
            ConstruireFeuille(12),
            ConstruireFeuille(15)
        ),
        ConstruireNoeud(
            '-',
            ConstruireNoeud(
                '*',
                ConstruireFeuille(7),
                ConstruireFeuille(10)
            ),
            ConstruireFeuille(3)
        )
    );

    Infixe(arbre);
    printf("\n");
    Prefixe(arbre);
    printf("\n");
    Postfixe(arbre);
    printf("\n");

    printf("%d\n", Eval(arbre));

    DetruireArbre(arbre);

    return 0;
}