#include "response.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* render(char * file) {
	FILE* f = fopen(file, "r");

	if (f == NULL)
		return NULL;

	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* temp = malloc(sizeof(char) * (fsize+1));
	char ch;
	int i = 0;

	while((ch = fgetc(f)) != EOF) {
		temp[i] = ch;
		i++;
	}

	fclose(f);
	return temp;
}