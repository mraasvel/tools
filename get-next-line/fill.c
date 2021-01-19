#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

void add_lines(char *buffer, int line_size) {
	for (int i = line_size - 1; i < SIZE; i += line_size) {
		buffer[i] = '\n';
	}
}

// give input file as parameter and write SIZE chars to it
int main(int argc, char *argv[])
{
	char *buffer;

	if (argc == 1)
		return (0);
	FILE* fp = fopen(argv[1], "w");
	if (fp == NULL)
		return (0);
	buffer = malloc(SIZE * sizeof(char));
	if (buffer == NULL) {
		printf("Malloc error\n");
		exit(EXIT_FAILURE);
	}
	memset(buffer, '1', SIZE);
	fwrite(buffer, 1, SIZE, fp);
	fwrite("\n", 1, 1, fp);
	return (0);
}