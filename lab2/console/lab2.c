#include <stdlib.h>
#include <stdio.h>

double** matrixMemoryAllocate(int rows){

	// Выделение памяти под матрицу, заданной размерности:

	double **tmp = (double**)malloc(sizeof(double*) * rows);	 
	for (int i = 0; i < rows+1; i++){
		*(tmp+i) = (double*) malloc(sizeof(double) * (rows+1));
	}
	return tmp;
}

double ** matrixClone(int rows, double ** source){
	double ** clone = matrixMemoryAllocate(rows);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < rows+1; j++){
			*(*(clone+i)+j) = *(*(source+i)+j);
		}
	}
	return clone;
}

double **matrixInput(int *rows){

	// Считывание размерности матрицы:
	printf("Введите уравнений в системе: ");							
	scanf("%d", rows);
	
	double **matrix = matrixMemoryAllocate(*rows);	 
	
	// Заполнение матрицы пользователем:
	for (int i = 0; i < *rows; i++){
		for (int j = 0; j <= (*rows); j++){
			if (j == (*rows)){
				printf("Введите свободный член для %d-го уравнения: ", i+1);
			}

			else {
				printf("Введите коэффициент при X%d у %d-го уравнения: ", j+1,i+1);
			}			
			scanf("%lf", *(matrix+i)+j);
		}
	}
	return matrix;
}

void matrixOutput(int rows, double **matrix){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < rows+1; j++){
			printf("%lf ", *(*(matrix+i)+j));
		}
		printf("\n");
	}
	printf("\n");
}

double* gaussMethod(int rows, double ** matrix){

	// Прямой ход:
	double multiplier;	
	for (int i = 0; i < rows-1; i++){
		for (int j = i + 1; j < rows; j++){
			multiplier = -(*(*(matrix+j)+i) / *(*(matrix+i)+i));			
			for (int k = i; k < rows+1; k++){
				*(*(matrix+j)+k) += *(*(matrix+i)+k) * multiplier;
			}
			printf("Умножим %d-ую строку на (%f) и прибавим к %d-ой:\n", i+1,multiplier, j+1);
			matrixOutput(rows, matrix);
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

void freeMemory(int rows, double ** array, int dimensionality){
	if (dimensionality == 1){
		free(*array);
	}
	else if (dimensionality == 2){		
		for (int i = 1; i < rows + 1; i++){
			free(*(array+i));
		}
		free(array);
	}
}

double *solutionCheck(int rows, double ** source, double * solution){

	double leftPart, *error;
	error = (double*)malloc(sizeof(double) * rows);
	for (int i = 0; i<rows; i++){
		leftPart = 0;
		for (int j = 0; j<rows; j++){
			leftPart += *(solution+j) * *(*(source+i)+j);
		}
		*(error+i) = *(*(source+i)+rows) - leftPart;
	}
	return error;
}

void arrayOutput(int rows, double * array, char *type){
	for (int i = 0; i<rows; i++){
		printf("%s%d = %lf\n", type, i+1, *(array+i));
	}
	printf("\n");
}



int main(){
	int rows;

	double ** originalMatrix = matrixInput(&rows); 				// Ввод матрицы
	double ** cloneMatrix = matrixClone(rows, originalMatrix);	// Создание клона
	double * solution;
	double * error;

	// Вывод исходной матрицы

	printf("\nИсходная матрица:\n");
	matrixOutput(rows, originalMatrix);

	// Вычисление ответов методом Гаусса

	solution = gaussMethod(rows, cloneMatrix);

	// Вывод ответов
	
	arrayOutput(rows, solution, "X");

	// Расчет невязок

	error = solutionCheck(rows, originalMatrix, solution);
	arrayOutput(rows, error, "ERROR");
	
	// Освобождение памяти
	
	freeMemory(3, originalMatrix, 2);
	freeMemory(3, cloneMatrix, 2);
	freeMemory(3, &solution, 1);
	freeMemory(3, &error, 1);
}