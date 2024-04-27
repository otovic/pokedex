#include "reader.h"
#include "pokemon.h"
#include "utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

Pokemon* readPokemonData(int* size) {
    FILE* file;
    errno_t err;
    char line[MAX_LINE_LENGTH];
    int count = 0;
	Pokemon* pokemonArray = NULL;

    err = fopen_s(&file, "pokemon.txt", "r");
    if (err != 0) {
        printf("Error opening file!\n");
        return NULL;
    }

    char* gender;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
		char* split = strtok(line, "|");
        int index = 0;
        char* types;

        while (split != NULL) {
			pokemonArray = (Pokemon*)realloc(pokemonArray, (count + 1) * sizeof(Pokemon));
            switch (index) {
                case 0:
				    strcpy(pokemonArray[count].id, split);
				    break;
                case 1:
					strcpy(pokemonArray[count].name, split);
					break;
                case 2:
					pokemonArray[count].height = atoi(split);
					break;
				case 3:
					pokemonArray[count].weight = atoi(split);
					break;
				case 4:
					strcpy(pokemonArray[count].category, split);
					break;
				case 5:
                    strcpy(pokemonArray[count].ability, split);
					break;  
				case 6:
					pokemonArray[count].gender = getGenderSize(split);
                    break;
				case 7:     
					pokemonArray[count].type = getPokemonTypes(split);
					break;
                default:
					break;
            }
			split = strtok(NULL, "|");
			index++;
        }
        count++;
    }
    
	*size = count;
    fclose(file);
    return pokemonArray;
}