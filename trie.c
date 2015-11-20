#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trie_initialize(Trie *T, int loc)
{
    T->next[loc] = (Trie*)malloc(sizeof(Trie));
    T->next[loc]->isWord = 0;
}
void trie_traverse(Trie *T) {
    char *word = (char*)calloc(sizeof(char),27);
    trie_print(T, word);
    free(word);
}

void trie_print(Trie *T, char *word){
    for(int i = 0; i < 53; i++) {
        if(T->next[i]!= NULL)
        {
            char *temp = word;
            while(*temp != '\0'){
                temp++;
            }
            *temp = trie_get_char(i);
            *(++temp) = '\0';
            if(T->next[i]->isWord)
            {
                printf("%s\n", word);
            }
            trie_print(T->next[i], word);
            temp--;
            *temp = '\0';
        }
    }
}

int trie_word_nodes(Trie *T, char *w)
{
    int loc,i,length = (int)strlen(w);
    for(i = 0; i < length; i++)
    {
        loc = trie_get_loc(w[i]);
        if(T->next[loc] == NULL)
            return 0;
        else T=T->next[loc];
    }
    if(T->isWord)
    {
        printf("%s\n", w);
    }
    trie_print(T,w);
    return 1;
}

char trie_get_char(int loc) {
    if(loc <= 25) return (char)(loc + 'a');
    else if(loc <= 51) return (char)(loc + 39);
    else return '\'';
}

int trie_get_loc(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    else if(c >= 'A' && c <= 'Z') return c - 39;
    else if(c == '\'') return 52;
    else return -1;
}

int trie_add_word(Trie *T, char *w)
{
    int i, loc, length = (int)strlen(w);
    for(i = 0; i < length; i++)
    {
        if((loc = trie_get_loc(w[i])) == -1)
        {
            printf("Invalid Entry\n");
            return -1;
        }
        if(T->next[loc] == NULL)
        {
            trie_initialize(T, loc);
            
        }
        if(i == length -1)
        {
                T->next[loc]->isWord = 1;
        }
        T=T->next[loc];
    }
    return 0;
}
