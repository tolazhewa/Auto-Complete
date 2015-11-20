//
//  main.c
//  Hewa_Tolaz_A3
//
//  Created by Tolaz on 2015-11-17.
//  Copyright © 2015 Tolaz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(int argc, const char * argv[])
{
    Trie *T= (Trie*)malloc(sizeof(Trie));
    //trie_initialize(T);
    char str[26];
    FILE *f = fopen("/Users/tolaz/Desktop/C/Projects/Hewa_Tolaz_A3/Hewa_Tolaz_A3/words.txt", "r");
    
    while(fscanf(f, "%s", str) != EOF)
    {
        trie_add_word(T, str);
    }
    fclose(f);
    
    //fgets(str, 26, stdin);
    trie_traverse(T);
    return 0;
}
