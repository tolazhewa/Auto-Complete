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
    FILE *f = fopen("/usr/courses/cps305/assign/assign3/american-english-no-accents", "r");
    if(f == NULL) 
	{
		printf("Your file don't make sense, bruh.\n");
		return 2;
	}
    while(fscanf(f, "%s", str) != EOF)
    {
        trie_add_word(T, str);
    }
    fclose(f);
    
    //fgets(str, 26, stdin);
    trie_traverse(T);
    return 0;
}
