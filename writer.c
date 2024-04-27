#include "writer.h"
#include "pokemon.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

Pokemon* addPokemon(Pokemon* pokemon) {
	printf("Pokemon name: ");
	scanf("%s", pokemon->name);
	printf("Pokemon height: ");
	scanf("%d", &pokemon->height);
	printf("Pokemon weight: ");
	scanf("%d", &pokemon->weight);
	printf("Pokemon category: ");
	scanf("%s", pokemon->category);
	printf("Pokemon ability: ");
	scanf("%s", pokemon->ability);
	printf("Pokemon gender: (1-male | 2-female | 3-both)");
	scanf("%d", &pokemon->gender);

	printf("Pokemon types: \n");
	char** type = malloc(2 * sizeof(char*));
	for (int i = 0; i < 2; i++) {
		printf("Enter %d. type: ", i + 1);
		type[i] = (char*)malloc(20 * sizeof(char));
		scanf("%s", type[i]);
	}
	pokemon->type = type;
}

void writePokemon(Pokemon* pokemon, int size) {
	FILE* file = fopen("pokemon.txt", "a");
	if (file == NULL) {
		printf("Error opening file!\n");
		return;
	}
	
	fprintf(file, "%s|%s|%d|%d|%s|%s|%s|%s\n", getID(size), pokemon[0].name, pokemon[0].height, pokemon[0].weight, pokemon[0].category, pokemon[0].ability, getGender(pokemon[0].gender), getTypes(pokemon[0].type, 2));
	
	fclose(file);
}