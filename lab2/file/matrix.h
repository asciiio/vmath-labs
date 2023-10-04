#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int equGetNum(FILE*);
double** equMatrixMemoryAllocate(int);
double** equMatrixInput(int, FILE*);
void equMatrixOutput(int, double**, FILE *);
void equAnswerOutput(int, double*, char*, FILE *);
double ** equMatrixClone(int, double**);
void equRowsReplace(int, int, double**);
int equFindMaxRowInCol(int, int, double**);

#endif // MATRIX_H