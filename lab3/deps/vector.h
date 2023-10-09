#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct vectors {
	double		*vectX;
	double		*vectY;
	uint16_t 	len;
} vect_t;


void vectRead(vect_t *dst, char *src);
void vectWrite(vect_t src);

#endif /* VECTOR */
