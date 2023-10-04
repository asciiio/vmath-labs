#include <stdlib.h>
#include <stdio.h>

double** matrixMemoryAllocate(int rows, int cols){

	// Выделение памяти под матрицу, заданной размерности:

	double **tmp = (double**)malloc(sizeof(double*) * rows);	 
	for (int i = 0; i<cols; i++){
		*(tmp+i) = (double*) malloc(sizeof(double) * cols);
	}
	return tmp;
}

double ** matrixClone(int rows, int cols, double ** source){
	double ** clone = matrixMemoryAllocate(rows,cols);
	for (int i = 0; i<rows; i++){
		for (int j = 0; j<cols; j++){
			*(*(clone+i)+j) = *(*(source+i)+j);
		}
	}
	return clone;
}

double **matrixInput(int *rows, int *cols){

	// Считывание размерности матрицы:
	printf("Введите количество строк: ");							
	scanf("%d", rows);
	printf("Введите количество столбцов: ");
	scanf("%d", cols);
	
	double **matrix = matrixMemoryAllocate(*rows,*cols);	 
	
	// Заполнение матрицы пользователем:
	for (int i = 0; i<*rows; i++){
		for (int j = 0; j<*cols; j++){
			printf("Введите [%d][%d] элемент: ", i,j);
			scanf("%lf", *(matrix+i)+j);
		}
	}
	return matrix;
}

void matrixOutput(int rows, int cols, double **matrix){
	for (int i = 0; i<rows; i++){
		for (int j = 0; j<cols; j++){
			printf("%lf ", *(*(matrix+i)+j));
		}
		printf("\n");
	}
	printf("\n");
}

void equRowsReplace(int row_a, int row_b, double **matrix){
	double *tmp = *(matrix+row_a);
	*(matrix+row_a) = *(matrix+row_b);
	*(matrix+row_b) = tmp;
}

int equFindMaxRowInCol(int curr_col, int rows, double **matrix){
	int max_row = curr_col;
	for (int j = curr_col+1; j < rows; j++) {
		if (*(*(matrix+j)+curr_col) > *(*(matrix+max_row)+curr_col)) {
			max_row = j;
		}
	}
	return max_row;
}

double* gaussMethod(int rows, int cols, double ** matrix){

	// Прямой ход:
	double multiplier;

	for (int i = 0; i < rows-1; i++){

		// Поиск максимального элемента в столбце
		int maxRow = equFindMaxRowInCol(i, rows, matrix);		

		// Обмен строк
		equRowsReplace(maxRow, i, matrix);

		for (int j = i + 1; j < rows; j++){
			multiplier = -(*(*(matrix+j)+i) / *(*(matrix+i)+i));			
			for (int k = i; k < rows+1; k++){
				*(*(matrix+j)+k) += *(*(matrix+i)+k) * multiplier;
			}
			printf("Умножим %d-ую строку на (%f) и прибавим к %d-ой:\n", i,multiplier, j);
			matrixOutput(rows, cols, matrix);
		}
	}

	//************************************************************************************** 

	// for (int i = 0; i < cols-2; i++){
	// 	for (int j = i+1; j < rows; j++){
	// 		multiplier = -(*(*(matrix+j)+i) / *(*(matrix+i)+i));			
	// 		for (int k = i; k < cols; k++){
	// 			*(*(matrix+j)+k) += *(*(matrix+i)+k) * multiplier;
	// 		}
	// 		printf("Умножим %d-ую строку на (%f) и прибавим к %d-ой:\n", i,multiplier, j);
	// 		matrixOutput(rows, cols, matrix);
	// 	}
	// }


	// Обратный ход
	int n = rows-1;
	double knownSum;
	double *answer = (double*)malloc(sizeof(double)*rows);

	*(answer+n) = *(*(matrix+n)+n+1) / *(*(matrix+n)+n);		// X[n] = A[n][n+1] / A[n][n]
	for (int i = n-1; i >= 0; i--){

		knownSum = 0;
		for (int j = i+1; j <= n; j++){
			*(*(matrix+i)+j) *= *(answer+j);
			knownSum += *(*(matrix+i)+j);
		}

		*(answer+i) = (*(*(matrix+i)+n+1) - knownSum) / *(*(matrix+i)+i);
	}
	return answer;
}

int main(){
	int rows, cols;

	double ** myMatrix = matrixInput(&rows, &cols); 		 // Ввод матрицы
	double ** tmpMatrix = matrixClone(rows, cols, myMatrix); // Создание клона
	double * answer;

	// Вывод исходной матрицы
	printf("\nИсходная матрица:\n");
	matrixOutput(rows,cols,myMatrix);

	// Вычисление ответов методом Гаусса

	answer = gaussMethod(rows,cols,tmpMatrix);

	// Вывод ответов
	for (int i = 0; i<rows; i++){
		printf("x%d = %lf\n", i+1, *(answer+i));
	}
	printf("\n");


	matrixOutput(rows,cols,myMatrix);
}