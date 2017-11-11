//Christopher Thompson
//Project 2
//C stands for control and appreciation for the nice stuff


#include "functions.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){
    
    Node* wordArr = malloc(1 * sizeof(Node)); //I can't really see more than a 1000 different words
    FILE* readIn; //read file pointer
    FILE* writeOut; //write file pointer
    char buffer[18]; //allocate buffer, can't see more than 1000 different words
    int count = 0;
    

    if(argc < 3){ //if the number of command line arguments is < 3, return EXIT_FAILURE
     return EXIT_FAILURE;
     }
    
    readIn = fopen(argv[1], "r"); //opens the selected argument file for reading
    writeOut = fopen(argv[2], "w"); //opens the selected argument file for writing
    
    if(readIn == NULL){ //if there
        printf("ERROR: fopen fail.\n");
        
        return EXIT_FAILURE; //exits if the file opens
    }
    
    int k = 0;
    while(fscanf(readIn, "%18s", buffer) == 1){ //loop to read in the words and count the number of words
        count++;
        wordArr = realloc(wordArr, 1); //reallocates a node for each word only use what I need
        modWord(buffer); //modifies the word
        strcpy(wordArr[k].word, buffer);
        
        ++k;
    }
    
    Node2* finalArr = malloc(count * sizeof(Node2)); //Allocate memory for the final array
    initialize(finalArr, count); //initialize the final array
    
    qsort(wordArr, count, sizeof(Node), compareStructs);
    
    int index = 0;
    for(int i = 0; i < count; i++){ //loop to access the array
        
        int compFront = strcmp(wordArr[i].word, wordArr[i+1].word); //compares the string with element i+1
        
        if((compFront != 0)){ //if the strings aren't equal
            strcpy(finalArr[index].word, wordArr[i].word); //then copy it over
            index++; //increment the index of the final array
        }
    }

    finalArr = countOccurrence(finalArr, wordArr, count); //counts the occurrence of words and returns array
    
    for(int x = 0; x < count; x++){
        fprintf(writeOut, "%s occurred  %d times\n", finalArr[x].word, finalArr[x].numTimes);
    }
    
    fclose(readIn); //close the readIn file
    fclose(writeOut); //close the writeOut file
    
    return EXIT_SUCCESS; // exit
    
    //and i'm finished
}
