#include "matrix.h"

int equGetNum(FILE *file_ptr){
	int num;
	fscanf(file_ptr, "%d ", &num);	
	return num;
}

double** equMatrixMemoryAllocate(int num){
	double **tmp = (double**)malloc(sizeof(double*) * num);	 
	for (int i = 0; i < num+1; i++){
		*(tmp+i) = (double*) malloc(sizeof(double) * (num+1));
	}
	return tmp;
}

double **equMatrixInput(int num, FILE *file_ptr){
	double **equMatrix = equMatrixMemoryAllocate(num);
	for (int i = 0; i < num; i++){
		for (int j = 0; j <= num; j++){
			fscanf(file_ptr, "%lf", *(equMatrix+i)+j);
		}
	}
	return equMatrix;
}

double **equMatrixClone(int num, double ** source){
	double **clone = equMatrixMemoryAllocate(num);
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num+1; j++){
			*(*(clone+i)+j) = *(*(source+i)+j);
		}
	}
	return clone;
}

void equAnswerOutput(int num, double *answer_vect, char *answer_type, FILE *file_ptr){
	for (int i = 0; i < num; i++){
		fprintf(file_ptr, "%s%d = %lf\n", answer_type, i+1, *(answer_vect+i));
	}
}

void equRowsReplace(int row_a, int row_b, double **matrix){
	double *tmp = *(matrix+row_a);
	*(matrix+row_a) = *(matrix+row_b);
	*(matrix+row_b) = tmp;
}

int equFindMaxRowInCol(int curr_col, int rows, double **matrix){
	int max_row = curr_col;
	for (int j = curr_col+1; j < rows; j++) {
		if (fabs(*(*(matrix+j)+curr_col)) > fabs(*(*(matrix+max_row)+curr_col))) {
			max_row = j;
		}
	}
	return max_row;
}