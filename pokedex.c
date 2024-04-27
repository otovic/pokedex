#include "pokemon.h"
#include "reader.h"
#include "printer.h"
#include "writer.h"
#include <stdlib.h>
#include <stdio.h>

void main()
{
    int size = 0;
    Pokemon* pokemonArray = readPokemonData(&size);
    
	if (pokemonArray == NULL) {
        printf("Failed to read Pokemon data\n");
        return 1;
    }

    int option = NULL;

    while (option != 4 && option < 4) {
		printf("Available options: \n");
		printf("1. Display all available Pokemon\n");
		printf("2. Display Pokemon information\n");
		printf("3. Enter new Pokemon\n");
		printf("4. Exit\n\n");
		printf("Enter option: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 1:
			displayAvailablePokemon(pokemonArray, size);
			printf("\n");
			break;
		case 2:
			displayAvailablePokemon(pokemonArray, size);
			printf("Choose pokemon to display data (enter index): ");
			int index;
			scanf("%d", &index);
			printf("\n");
			displayPokemonInformation(pokemonArray, index - 1);
			break;
		case 3:
			printf("Enter new Pokemon data: \n");
			Pokemon* newPokemon = (Pokemon*)malloc(sizeof(Pokemon));
			addPokemon(newPokemon);
			writePokemon(newPokemon, size);
			printf("Pokemon added to Pokedex! \n");
			free(newPokemon);
			pokemonArray = readPokemonData(&size);
			break;
		case 4:
			option == 3;
			break;
		default:
			printf("Invalid option\n");
			break;
		}
    }

	free(pokemonArray->type);
    free(pokemonArray);
}