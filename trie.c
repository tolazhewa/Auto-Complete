/*
 * Name: Tolaz Hewa, Bojan Oro, Alessandro Profenna
 * Date: November 20th, 2015
 * Course: CPS305
 * Project: Assignment 3: Making an auto-complete app using a trie tree.
 * File: Trie c file that contains all the functions that would for the trie needed.
 */
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * function: initialize needed node
 */
void trie_initialize(Trie *T, int loc) {
	T->next[loc] = (Trie*)malloc(sizeof(Trie));
	T->next[loc]->isWord = 0;
}

/*
 * function: frees all nodes (pointers) of the trie
 */
void trie_free(Trie *T) {
	int i;
	//loops through all the nodes and free()s them
	for(i = 0; i < 53; i++) {
		if(T->next[i] != NULL) {
			trie_free(T->next[i]);
			free(T->next[i]);
		}
	}
}
/*
 * function: prints all the possible auto-complete possibilities
 */
void trie_print(Trie *T, char *word){
	int i;
	for(i = 0; i < 53; i++) {
		if(T->next[i]!= NULL) {
			//adds to the word
			char *temp = word;
			while(*temp != '\0') 
				temp++;
			*temp = trie_get_char(i);
			*(++temp) = '\0';
			//prints the word if it is a word (isWord == 1)
			if(T->next[i]->isWord)
				printf("%s\n", word);
			//recursively calls itself
			trie_print(T->next[i], word);
			//takes off a single a character from the word
			temp--;
			*temp = '\0';
		}
	}
}

/*
 * function: navigates to and call trie_print to print auto-complete possibilities
 */
void trie_word_nodes(Trie *T, char *w) {
	int loc,i,length = (int)strlen(w);
	//loops through the trie until it gets to the last node of the word.
	for(i = 0; i < length; i++) {
		loc = trie_get_loc(w[i]);
		if(T->next[loc] == NULL)
			return;
		else T=T->next[loc];
	}
	//if it is a word, it prints it
	if(T->isWord) printf("%s\n", w);
	//calls on trie_print function to print all other auto-complete
	trie_print(T,w);
}
/*
 * function: gets the location of a character in the array
 */
char trie_get_char(int loc) {
	if(loc == 0) return '\'';
	else if(loc <= 26) return (char)(loc + 96);
	else return (char)(loc + 38);
}
/*
 * function: gets the character based on its location on the array.
 */
int trie_get_loc(char c) {
	if(c >= 'a' && c <= 'z') return c - 96;
	else if(c >= 'A' && c <= 'Z') return c - 38;
	else if(c == '\'') return 0;
	else return -1;
}
/*
 * function: adds word to the trie one node at a time.
 */
void trie_add_word(Trie *T, char *w) {
	int i, loc, length = (int)strlen(w);
	//loop to add all the nodes of
	for(i = 0; i < length; i++) {
		//if it is not ['a-zA-Z], then indicate false input
		loc = trie_get_loc(w[i]);
		//if the node doesn't exist: create node using trie_initialize()
		if(T->next[loc] == NULL)
			trie_initialize(T, loc);
		//if its the last letter, indicate that it is a word.
		if(i == length-1)
			T->next[loc]->isWord = 1;
		else
			T = T->next[loc];
	}
}
