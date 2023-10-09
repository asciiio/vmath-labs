#include "matrix.h"

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
