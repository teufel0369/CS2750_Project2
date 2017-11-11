#include "functions.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//initializes Node2
Node2* initialize(Node2* wordArray, int count){
    
    for(int i = 0; i < count-1; i++){
        wordArray[i].numTimes = 0;
    }
    
    return wordArray;
}


//modifies the word removing all non-essential characters
char modWord(char buffer[18]){
    unsigned long length = strlen(buffer); //defines the length of the buffer
    
    for(int i = 0; i < length; i++){ //loop to access string
        buffer[i] = tolower(buffer[i]); //converts all characters to lower case
        
        if(!(isalnum(buffer[i]))){
            for(int j = i; j < strlen(buffer); j++){ //for loop to remove all non-alphanumeric characters
                buffer[j] = buffer[j + 1];
            }
        }
    }
    
    unsigned long len = strlen(buffer); //defines the length of the buffer
    buffer[len] = '\0'; //appends a null terminator to the end
    
    return *buffer;
}

//compare structs for qsort
int compareStructs(const void* a, const void* b){
    Node* node1 = (Node*)a; //for comparison in qsort
    Node* node2 = (Node*)b; //for comparison in qsort
    
    return strcmp(node1->word, node2->word); //strcmp
}

//counts the occurrences and increments numTimes in finalArr; returns finalArr
Node2* countOccurrence(Node2* finalArr, Node* wordArr, int count){
    int index = 0;
    int i = 0;
    
    while(i < count){
        int comp = strcmp(finalArr[i].word, wordArr[index].word);
        
        if(comp == 0){
            finalArr[i].numTimes++;
            ++index;
        }
        else{
            ++i;
        }
    }
    
    return finalArr;
}
