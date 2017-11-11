#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>

typedef int bool; //defines what a boolean is
#define false 0; //defines false
#define true 1;//defines true

#define BUFSIZE 18
#define SIZE 400

typedef struct Word{ //struct
    
    char word[18];

}Node;

typedef struct Sorted{ //sorted struct array
    
    char word[18];
    int numTimes;
    
}Node2;

char modWord(char buffer[18]); //converts the word to lower case
Node2* initialize(Node2* wordArray, int count); //initializes the array of structs
int compareStructs(const void* a, const void* b); //compares the structs for qsort
Node2* countOccurrence(Node2* finalArr, Node* wordArr, int count);
#endif 
