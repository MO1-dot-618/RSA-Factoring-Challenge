#ifndef _FACTORS_H
#define _FACTORS_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__int128 atoll128(char *str);
void print128(__int128 x);
int factorize_big(__int128 num);
int factorize(char *buffer);

#endif
