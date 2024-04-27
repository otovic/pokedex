#include "utility.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_WORDS 3
#define MAX_WORD_LENGTH 100

int getGenderSize(char* g) {	
	int size = 0;
    int m = 0;
	int f = 0;
	
    while (*g != '\0') {
		if (*g == 'm') m++;
		else if (*g == 'f') f++;
		g++;
    }

	if (m > 0 && f > 0) size = 3;
	else if (m > 0) size = 1;
	else if (f > 0) size = 2;
	
	return size;
}

char* getGender(int gender) {
	char* g = (char*)malloc(2, sizeof(char));
    if (gender == 1) {
        g = (char*)malloc(2 * sizeof(char));
        strcpy(g, "m");
    }
    else if (gender == 2) {
        g = (char*)malloc(2 * sizeof(char));
        strcpy(g, "f");
    }
    else if (gender == 3) {
        g = (char*)malloc(4 * sizeof(char));
        strcpy(g, "m,f");
    }
    else {
        g = NULL;
    }
    return g;
}

char* getID(int id) {
    char idStr[6];
    snprintf(idStr, sizeof(idStr), "%05d", id);

    int number = atoi(idStr + 1);
    number++;

    char* nextID = (char*)malloc(6);
    if (nextID == NULL) return NULL;

    snprintf(nextID, 6, "%05d", number);

    return nextID;
}

char* getTypes(char** types, int size) {
    int total_length = 0;
    for (int i = 0; i < size; i++) {
        total_length += strlen(types[i]);
        if (i < size - 1) total_length++;
    }

    char* new_types = (char*)malloc(total_length + 1);
    if (new_types == NULL) return NULL;

    new_types[0] = '\0';
    for (int i = 0; i < size; i++) {
        strcat(new_types, types[i]);
        if (i < size - 1) strcat(new_types, ",");
    }

    return new_types;
}

char** getPokemonTypes(char* input) {
    char** words = calloc(3, sizeof(char*));

	char* token = strtok(input, ",");
    int i = 0;

    while (token != NULL) {
        words[i] = (char*)calloc(30, sizeof(char));
        strcpy(words[i], token);
        token = strtok(NULL, ",");
        i++;
    }

	return words;
}