#include "pokemon.h"

#ifndef PRINTER_H
#define PRINTER_H

void displayAvailablePokemon(Pokemon* pokemonArray, int size);
void displayPokemonInformation(Pokemon* pokemonArray, int index);
void printGender(int index);
void printType(char** type);

#endif PRINTER_H