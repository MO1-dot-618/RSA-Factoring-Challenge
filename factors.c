#include "factors.h"



/**
  * main - main function to factorize numbers
  * @argc: number of arguments
  * @argv: arguments
  * Return: 0 (success)
  */
int main(int argc, char **argv)
{
	FILE *file;
	size_t count = 0;
	char *buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while(getline(&buffer, &count, file) != -1)
	{
		factorize(buffer);
	}
	free(buffer);
	fclose(file);
	return (0);
}

int factorize(char *buffer)
{
	long long int num, i;

	num = atoll(buffer);
	for (i = 2; i < num / 2 + 1; i++)
	{
		if (num % i == 0)
		{
			printf("%lli=%lli*%lli\n", num, num / i, i);
			break;
		}
	}
	return (0);
}
