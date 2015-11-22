/*
 * Name: Tolaz Hewa, Bojan Oro, Alessandro Profenna
 * Date: November 20th, 2015
 * Course: CPS305
 * Project: Assignment 3: Making an auto-complete app using a trie tree.
 * File: the main driver of the Trie. Creates Trie, gets input, and outputs using the trie structs and functions
 */
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * function: main method to start the program
 */
int main(int argc, const char *argv[]) {
	//declarations and creation of the Trie
	char *temp, *str = (char*)calloc(sizeof(char), 25);
	FILE *f = fopen("/Users/tolaz/desktop/assign3/american-english-no-accents","r");
	Trie *T = (Trie*)malloc(sizeof(Trie));

	//opens file and adds to the trie
	if(f == NULL) {
		printf("There is no such file.\n");
		return 2;
	}
	while(fscanf(f,"%s", str) != EOF) {
		trie_add_word(T,str);
	}
	fclose(f);

	//getting input and outputting all the possible auto-completes
	printf("Enter String: ");
	while(fgets(str, 26, stdin) != NULL){
		temp = str;
		while (*temp != '\n')
			temp++;
		*temp = '\0';
		trie_word_nodes(T, str);
		printf("Enter String: ");
	}
	printf("\n");

	//freeing all the memory reserved using trie_free() and freeing everything else declared in main
	trie_free(T);
	free(str);
	free(T);
}
