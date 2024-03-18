#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAILLE 15

void ChangeEtat(int M[TAILLE][TAILLE]);
void Imprime(int M[TAILLE][TAILLE]);
void ConfigInit(int M[TAILLE][TAILLE]);
int nbVoisins(int M[TAILLE][TAILLE], int i, int j);
int BinRandom();
int EstVivante(int M[TAILLE][TAILLE], int i, int j);
void ImprimeDifférence(int M1[TAILLE][TAILLE], int M2[TAILLE][TAILLE]);



void Imprime(int M[TAILLE][TAILLE]) {
	for (unsigned int i = 1; i<TAILLE-1; i++) {
		for (unsigned int j = 1; j<TAILLE-1; j++) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}


void ConfigInit(int M[TAILLE][TAILLE]) {
	for (unsigned int i = 0; i<TAILLE; i++) {
		for (unsigned int j = 0; j<TAILLE; j++) {
			if (i==0 || j == 0 || i == TAILLE-1 || j == TAILLE-1) {
				M[i][j] = 0;
			} else {
				M[i][j] = BinRandom();
			}
		}
	}
	return;
}

int nbVoisins(int M[TAILLE][TAILLE], int i, int j) {
	int result = M[i+1][j] +  M[i-1][j] + M[i][j+1] + M[i][j-1];
	return result;
}

int BinRandom() {
	return(rand() % 2);
}

int EstVivante(int M[TAILLE][TAILLE], int i, int j) {
	int voisins = nbVoisins(M, i, j);
	if (voisins == 0 || voisins == 4) {
		return 0;
	} else if (voisins == 2 || voisins == 3) {
		return 1;
	} else {
		return M[i][j];
	}
}

void ChangeEtat(int M[TAILLE][TAILLE]) {
	for (unsigned int i = 1; i<TAILLE-1; i++) {
		for (unsigned int j = 1; j<TAILLE-1; j++) {
			M[i][j] = EstVivante(M, i, j);
		}
	}
	return;
}

void ImprimeDifférence(int M1[TAILLE][TAILLE], int M2[TAILLE][TAILLE]) {
	for (unsigned int i = 1; i<TAILLE-1; i++) {
		for (unsigned int j = 1; j<TAILLE-1; j++) {
			printf("%d ", M2[i][j] - M1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void copie_tableau(int M1[TAILLE][TAILLE], int M2[TAILLE][TAILLE]) {
	for (unsigned int i = 1; i<TAILLE-1; i++) {
		for (unsigned int j = 1; j<TAILLE-1; j++) {
			M2[i][j] = M1[i][j];
		}
	}
	return;
}


int main() {
	srand(time(NULL));

	int M[TAILLE][TAILLE];
	int old_M[TAILLE][TAILLE];

	int NbEtapes;
	printf("NbEtapes = ");
	scanf("%d", &NbEtapes);

	ConfigInit(M);
	Imprime(M);

	for (unsigned int i = 0; i<NbEtapes; i++) {
		printf("\nEtape %d : \n", i);
		copie_tableau(M, old_M);
		ChangeEtat(M);
		Imprime(M);
		ImprimeDifférence(M, old_M);
		copie_tableau(M, old_M);
	}


	return 0;
}
