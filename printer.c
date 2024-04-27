#include "printer.h"
#include "pokemon.h"
#include <stdio.h>

void displayAvailablePokemon(Pokemon* pokemonArray, int size) {
	printf("Available pokemons: \n");
	for (int i = 0; i < size; i++) {
		printf("%d: ", i + 1);
		printf("%s\n", pokemonArray[i].name);
	}
}

void displayPokemonInformation(Pokemon* pokemonArray, int index) {
	printf("Data for pokemon with index %d: \n", index + 1);
	printf("Pokemon ID: %s\n", pokemonArray[index].id);
	printf("Name: %s\n", pokemonArray[index].name);
	printf("Height: %dcm\n", pokemonArray[index].height);
	printf("Weight: %dkg\n", pokemonArray[index].weight);
	printf("Category: %s\n", pokemonArray[index].category);
	printf("Ability: %s\n", pokemonArray[index].ability);
	printGender(pokemonArray[index].gender);
	printType(pokemonArray[index].type);
	printf("\n");
}

void printGender(int gender) {
	if (gender == 1) printf("Gender: Male\n");
	else if (gender == 2) printf("Gender: Female\n");
	else printf("Gender: Male | Female\n");
}

void printType(char** type) {
	printf("Type: ");
	for (int i = 0; i < 2; i++) {
		printf("%s", type[i]);
		if (i == 0) printf(" | ");
	}
	printf("\n");
}