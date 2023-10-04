#include "gauss.h"

double* gaussMethod(int rows, double ** matrix){

	// Прямой ход
	
	double multiplier;	
	for (int i = 0; i < rows-1; i++){

		// Поиск максимального элемента в столбце:
		int maxRow = equFindMaxRowInCol(i, rows, matrix);		

		// Обмен строк:
		equRowsReplace(maxRow, i, matrix);

		// Прямой ход:
		for (int j = i + 1; j < rows; j++){		
			multiplier = -(*(*(matrix+j)+i) / *(*(matrix+i)+i));			
			for (int k = i; k < rows+1; k++){
				*(*(matrix+j)+k) += *(*(matrix+i)+k) * multiplier;
			}
		}
	}

	// Обратный ход
	int n = rows-1;
	double knownSum;
	double *solution = (double*)malloc(sizeof(double) * rows);

	*(solution+n) = *(*(matrix+n)+n+1) / *(*(matrix+n)+n);		// X[n] = A[n][n+1] / A[n][n]
	for (int i = n-1; i >= 0; i--){

		knownSum = 0;
		for (int j = i+1; j <= n; j++){
			*(*(matrix+i)+j) *= *(solution+j);
			knownSum += *(*(matrix+i)+j);
		}

		*(solution+i) = (*(*(matrix+i)+n+1) - knownSum) / *(*(matrix+i)+i);
	}
	return solution;
}

double* solutionCheck(int rows, double ** source, double * solution){

	double leftPart;
	double *error = (double*)malloc(sizeof(double) * rows);
	for (int i = 0; i<rows; i++){
		leftPart = 0;
		for (int j = 0; j<rows; j++){
			leftPart += *(solution+j) * *(*(source+i)+j);
		}
		*(error+i) = *(*(source+i)+rows) - leftPart;
	}
	return error;
}
