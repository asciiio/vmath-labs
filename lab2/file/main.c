#include "matrix.h"
#include "gauss.h"

int main(int argc, char **argv){	
	FILE *file_write = fopen("answers.txt", "w+");
	FILE *file_read = fopen(argv[1],"r");

	int num = equGetNum(file_read);								// Получаем количество уравнений

	double **equMatrix = equMatrixInput(num, file_read);		// Считываем матрицу

	double **equMatrixCopy = equMatrixClone(num, equMatrix);	// Клонируем матрицу

	double *answers = gaussMethod(num, equMatrix);				// Решаем методом Гаусса

	equAnswerOutput(num, answers, "X", file_write);				// Выводим корни в файл

	double *error = solutionCheck(num, equMatrixCopy, answers);	// Расчет невязок
	
	equAnswerOutput(num, error, "ERROR", file_write);			// Вывод невязок в файл
}
