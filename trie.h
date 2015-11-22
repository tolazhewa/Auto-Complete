/*
 * Name: Tolaz Hewa, Bojan Oro, Alessandro Profenna
 * Date: November 20th, 2015
 * Course: CPS305
 * Project: Assignment 3: Making an auto-complete app using a trie tree
 * File: Trie Header: contains the struct and all the prototypes
 */

#ifndef trie_h
#define trie_h

/*
 * struct: contains an array of nodes [a-zA-Z'] and an integer boolean to tell if the node has reached a word
 */
typedef struct TrieTag {
	struct TrieTag *next[53];
	int isWord;
}Trie;

/*
 * All the prototypes for trie functions/methods
 */
void trie_initialize(Trie *T, int loc);
void trie_print(Trie *T, char *word);
void trie_free(Trie *T);
void trie_word_nodes(Trie *T, char *w);
char trie_get_char(int loc);
int trie_get_loc(char c);
void trie_add_word(Trie *T, char *w);

#endif
