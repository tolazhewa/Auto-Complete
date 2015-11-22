#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
	char *temp, *str = (char*)calloc(sizeof(char), 25);
	FILE *f;
	Trie *T = (Trie*)malloc(sizeof(Trie));
	f = fopen("/usr/courses/cps305/assign/assign3/american-english-no-accents","r");
	if(f == NULL) {
		printf("There is no such file.");
		return 2;
	}
	while(fscanf(f,"%s", str) != EOF) {
		trie_add_word(T,str);
	}
	printf("Enter String: ");
	while(fgets(str, 26, stdin) != NULL){
		temp = str;
		while (*temp != '\n') temp++;
		*temp = '\0';
		trie_word_nodes(T, str);
		printf("Enter String: ");
	}
	printf("\n");
	free(str);
	free(T);
}
