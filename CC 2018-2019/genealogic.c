#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

typedef struct SPersonne SPersonne;
typedef struct SEnfant SEnfant;


typedef struct SPersonne {
    char Nom[50];
    char Prenom[50];
    char Sexe;
    SPersonne* Pere;
    SPersonne* Mere;
    SEnfant* Enfant;
    int NbEnfants;
} SPersonne;

typedef struct SEnfant {
    SPersonne* Parent;
    SPersonne* Individu;
    SEnfant* Enfant_Suivant;
} SEnfant;




SPersonne* AjoutPersonne(char* Nom, char* Prenom, char Sexe) {
    SPersonne* personne = (SPersonne*) malloc(sizeof(SPersonne));
    if (personne) {
        strcpy(personne->Nom, Nom);
        strcpy(personne->Prenom, Prenom);
        personne->Sexe = Sexe;
        personne->Enfant = NULL;
        personne->Pere = NULL;
        personne->Mere = NULL;
    }
    return personne;
}

void AfficherPersonne(SPersonne* personne) {
    printf("%s %s %c", personne->Prenom, personne->Nom, personne->Sexe);
}


void AttacherPersonne(SPersonne* personne, SPersonne* pere, SPersonne* mere) {
    personne->Pere = pere;
    personne->Mere = mere;

    SEnfant* enfant_pere = (SEnfant*) malloc(sizeof(SEnfant));
    SEnfant* enfant_mere = (SEnfant*) malloc(sizeof(SEnfant));

    enfant_pere->Individu = personne;
    enfant_mere->Individu = personne;

    enfant_pere->Parent = pere;
    enfant_mere->Parent = mere;

    enfant_pere->Enfant_Suivant = pere->Enfant;
    enfant_mere->Enfant_Suivant = mere->Enfant;

    pere->Enfant = enfant_pere;
    mere->Enfant = enfant_mere;

    pere->NbEnfants++;
    mere->NbEnfants++;
}

void AfficherEnfants(SPersonne* personne) {
    SEnfant* enfant = personne->Enfant;
    while (enfant) {
        AfficherPersonne(enfant->Individu);
        enfant = enfant->Enfant_Suivant;
    }
}

void AfficherParents(SPersonne* personne) {
    AfficherPersonne(personne->Pere);
    AfficherPersonne(personne->Mere);
}

void AfficherFratrie(SPersonne* personne) {
    SEnfant* enfant = personne->Pere->Enfant;
    while (enfant) {
        if (enfant->Individu->Mere == personne->Mere) {
            if (enfant->Individu->Sexe == "M") {
                printf("Frère : ");
            } else {
                printf("Soeur : ");
            }
        } else {
            if (enfant->Individu->Sexe == "M") {
                printf("Demi-frère : ");
            } else {
                printf("Demi-Soeur : ");
            }
        }
        AfficherPersonne(enfant->Individu);
        enfant = enfant->Enfant_Suivant;
    }

    enfant = personne->Mere->Enfant;
    while (enfant) {
        if (enfant->Individu->Pere == personne->Pere) {
            if (enfant->Individu->Sexe == "M") {
                printf("Frère : ");
            } else {
                printf("Soeur : ");
            }
        } else {
            if (enfant->Individu->Sexe == "M") {
                printf("Demi-frère : ");
            } else {
                printf("Demi-Soeur : ");
            }
        }
        AfficherPersonne(enfant->Individu);
        enfant = enfant->Enfant_Suivant;
    }
}



int main() {


	return 0;
}