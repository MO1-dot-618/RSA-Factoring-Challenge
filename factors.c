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
	__int128 bigN;

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
		bigN = atoll128(buffer);
		if(bigN > 9223372036854775806)
			factorize_big(bigN);
		else
			factorize(buffer);
	}
	free(buffer);
	fclose(file);
	return (0);
}

/**
  * factorize - function to factorize numbers (no bigger than long long)
  * @buffer: string containing number
  * Return: 0 (Success)
  */
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

/**
  * atoll128 - atoll for 128-byte numbers
  * @str: string to convert
  * Return: 128-byte number
  */
__int128 atoll128(char *str)
{
	__int128 result = 0;
	while(*str && *str != '\n' && *str != '\0')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return result;
}

/**
  * print128 - prints 128èbyte numbers
  * @x: number to print
  */

void print128(__int128 x)
{
	char b;
	if(x) print128(x / 10);
	else return;
	b = x % 10 + '0';
	printf("%c", b);
}

/**
  * factorize_big - factrorizing giant numbers (bigger than long long)
  * @buffer: string containing number
  * Return: 0 (Success)
  */

int factorize_big(__int128 num)
{
	__int128 i;

	for (i = 2; i < (num / 2 + 1); i++)
	{
		if (num % i == 0)
		{
			print128(num); printf("=");
			print128(num / i); printf("*");
			print128(i); printf("\n");
			break;
		}
	}
	return (0);
}
