#include "least.h"

static double **gramatrix;

double* least(vect_t vcts, uint16_t pol_pow){
	double S, R;
	uint16_t i, j;
	uint16_t N = vcts.len;
	uint16_t M = pol_pow + 1;
	double *coefs;
	
	// Создаем вектор Q
	double *Q = (double*) malloc (sizeof(double) * N);
	
	// Создаем матрицу Грама
	gramatrix = (double**)malloc(sizeof(double*) * M);
	for (i = 0; i < M; i++){
		*(gramatrix + i) = (double*) malloc(sizeof(double) * (M+1));
	}
	
	// Заполняем вектор единицами
	for (i = 0; i < vcts.len; i++){
		Q[i] = 1;
	}
	
	// Алгоритм формирования матрицы Грамма (первые строки + последний столбец)
	for (i = 0; i < M; i++) {
		
		S = 0;
		R = 0;
		
		for (j = 0; j < N; j++) {
			S = S + Q[j];
			R = R + Q[j] * vcts.vectY[j];
			Q[j] = Q[j] * vcts.vectX[j];			
		}
				
		gramatrix[0][i] = S;
		gramatrix[i][M] = R;		
	}
	
	// Заполняем оставшиеся строки
	for (i = 1; i < M; i++){
	
		S = 0;
		
		for (j = 0; j < N; j++) {
			if (j < M) gramatrix[i][j] = gramatrix[i-1][j+1];			
			S = S + Q[j];
			Q[j] = Q[j] * vcts.vectX[j];			
		}
		
		gramatrix[i][M-1] = S;		
	}  	
	coefs = gaussMethod(M, gramatrix);
	
	free(Q);
	
	for (int i = 0; i < M; i++){
		free(*(gramatrix+i));
	}	
	free(gramatrix);
	return coefs;
}
