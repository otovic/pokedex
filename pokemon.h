#ifndef POKEMON_H
#define POKEMON_H

typedef struct {
	char id[6];
	char name[20];
	int height;
	int weight;
	char category[20];
	char ability[40];
	int gender;
	char** type;
} Pokemon;

#endif POKEMON_H