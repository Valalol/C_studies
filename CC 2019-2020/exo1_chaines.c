#include <stdlib.h>
#include <stdio.h>
#include <strings.h>



void Substitue(char* input) {
	int i = 0;
	char letter = input[0];
	while (letter != '\0') {
		if (letter == ' ') {
			input[i] = '_';
		}
		i++;
		letter = input[i];
	}
	return;
}


char* Supprime(char* input) {
	int length = strlen(input);
	char* output = malloc(sizeof(char)*length);
	int i = 0;
	int j = 0;
	char letter = input[0];
	while (letter != '\0') {
		if (letter != ' ') {
			output[j] = letter;
			j++;
		}
		i++;
		letter = input[i];
	}
	output[j] = '\0';
	return output;
}


int SubstitueMieux(char* input, char* substitution, int start, int max_char) {
	int n = 0; // charactères subsitués
	int i = 0;
	char letter = input[0];
	while (letter != '\0' && i < start+max_char-1) {
		if (i>= start) {
			input[i] = substitution[i-start];
			n++;
		}
		i++;
		letter = input[i];
	}
	return n;
}

void printstr(char* s, int n) {
	for (int i = 0; i<n && s[i] != '\0' ; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
}

char* Remplace(char* input, char* find, char* replace) {
	char* output = (char*) malloc(sizeof(char)*200);
	int i = 0;
	int j = 0;
	char letter = input[0];
	while (letter != '\0') {

		if (strncmp(input+i, find, strlen(find)) == 0) {
			for (int index = 0; index<strlen(replace); index++) {
				output[j+index] = replace[index];
			}
			i = i + strlen(find);
			j = j + strlen(replace);
		} else {
			output[j] = letter;
			i++;
			j++;
		}
		letter = input[i];
	}
	output[j] = '\0';
	return output;
}







int main() {
	printf("\nTest de la fonction Substitute\n");
	char s1[] = "hey comment ça va ?";
	printf("%s\n", s1);
	Substitue(s1);
	printf("%s\n", s1);


	printf("\nTest de la fonction Supprime\n");
	char s2[] = "hey comment ça va ?";
	printf("%s\n", s2);
	char* out = Supprime(s2);
	printf("%s\n", out);
	free(out);


	printf("\nTest de la fonction SubstitueMieux\n");
	char s3[] = "bonjour à tous" ;
	printf("%s\n", s3);
	SubstitueMieux(s3, "soirée", 3, 4);
	printf("%s\n", s3);


	printf("\nTest de la fonction Remplace\n");
	char* s4;
	s4 = Remplace("Examen de langage C", "langage", "cours de");
	printf("%s\n", s4);
	s4 = Remplace("un peu de C, puis un peu de C++", "un peu", "beaucoup");
	printf("%s\n", s4);
	s4 = Remplace("Cette chaîne de caractère est pénible", "te", " exercice sur la");
	printf("%s\n", s4);
	free(s4);

	return 0;
}
