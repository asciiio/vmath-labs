#ifndef EASY_MATRIX_H
#define EASY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct VectorZ {
		
	double*		vectX;
	double*		vectY;
	uint16_t	len;
	
} vect_t;

void getVectFromFile(char * file_name);
void outVectConsole();
#endif /* EASY_MATRIX_H */
