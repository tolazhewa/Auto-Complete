#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	char *temp, *str = (char*)calloc(sizeof(char), 27);
	FILE *f;
	Trie *T = (Trie*)malloc(sizeof(Trie));
	f = fopen("/Users/tolaz/Desktop/assign3/american-english-no-accents","r");
	if(f == NULL)
	{
		printf("There is no such file.");
		return 2;
	}
	while(fscanf(f,"%s", str) != EOF)
	{
		trie_add_word(T,str);
	}
	while(1) {
		printf("Enter String:");
		fgets(str, 26, stdin);
		temp = str;
		while (*temp != '\n') temp++;
		*temp = '\0';
		if (!trie_word_nodes(T, str)) {
			printf("Not in dictionary!\n");
		}
	}
}
