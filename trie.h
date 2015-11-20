//
//  trie.h
//  Hewa_Tolaz_A3
//
//  Created by Tolaz on 2015-11-17.
//  Copyright © 2015 Tolaz. All rights reserved.
//

#ifndef trie_h
#define trie_h

#include <stdio.h>

typedef struct TrieTag Trie;
struct TrieTag
{
    Trie *next[53];
    int isWord;
    //int isNode;
};

void trie_initialize(Trie *T, int loc);
void trie_traverse(Trie *T);
void trie_print(Trie *T, char *word);
int trie_node_exists(Trie *T, char *w);
int trie_has_word(Trie *T, char *w);
int trie_print_word(Trie *T, char *w);
//Trie* trie_word_node(Trie *T, char *w);
char trie_get_char(int loc);
int trie_get_loc(char c);
int trie_add_word(Trie *T, char *w);



#endif /* trie_h */

