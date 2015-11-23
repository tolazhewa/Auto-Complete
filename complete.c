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
 * Opens file and adds to the trie
 */
void trie_file_read(Trie **T) {
    //declerations
    FILE *f;
    char *str = (char*)calloc(sizeof(char), 26);
    
    //file opening and error checking
    f = fopen("/usr/courses/cps305/assign/assign3/american-english-no-accents","r");
	if(f == NULL) {
		printf("There is no such file.\n");
        return;
	}
    //adds all the words to the trie
	while(fscanf(f,"%s", str) != EOF) {
		trie_add_word(*T,str);
	}
    //closing file and freeing memory allocated for str
	fclose(f);
    free(str);
}
/*
 * Gets input and outputting all the possible auto-completes
 */
void trie_auto_complete(Trie **T) {
    
    //declarations
    char *temp, *str = (char*)calloc(sizeof(char), 26);
    int isValid = 1;
    
    //user input and calls auto-completes
    printf("Enter String: ");
    while(fgets(str, 26, stdin) != NULL) {
        
        //checking if input is valid
        temp = str;
        while(*temp != '\n') {
            if(trie_get_loc(*temp) == -1) {
                isValid = 0;
                printf("Invalid input!\n");
                break;
            }
            temp++;
        }
        
        //if input is valid, then continue
        if(isValid){
            
            //remove the \n at the end
            temp = str;
            while (*temp != '\n')
                temp++;
            *temp = '\0';
            //calls on all the possible auto-completes
            trie_word_nodes(*T, str);
        }
        printf("Enter String: ");
    }
    printf("\n");
    free(str);
}

/*
 * function: main method to start the program
 */
int main(int argc, const char *argv[]) {
    
	//declaration and creation of the Trie
    Trie *T;
    trie_initialize(&T);
    
    //calls method to read from file
    trie_file_read(&T);
    
    //calls method to get input and auto complete
    trie_auto_complete(&T);
    
	//freeing all the memory reserved using trie_free() and freeing everything else declared in main
	trie_free(T);
	free(T);
}
