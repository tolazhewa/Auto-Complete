#ifndef trie_h
#define trie_h

typedef struct TrieTag {
	struct TrieTag *next[54];
}Trie;

void trie_initialize(Trie *T, int loc);
void trie_print(Trie *T, char *word);
int trie_word_nodes(Trie *T, char *w);
char trie_get_char(int loc);
int trie_get_loc(char c);
int trie_add_word(Trie *T, char *w);

#endif
