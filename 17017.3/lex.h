// lex.h the header file for the scanner
#ifndef LEX_H
#define LEX_H

#define END 256
#define NUM 257

#include<stdio.h>

extern int pos;

typedef struct
{
	int tokenClass;
	int val;
}token_t;

extern token_t token;
void getNextToken(void);

#endif
