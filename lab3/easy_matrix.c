#include "easy_matrix.h"

static vect_t vectors;

static void getSplitVect(double *summaryVect){
	
	// Выделяем память под векторы (x и y)
	
	vectors.vectX = (double*) malloc(sizeof(double) * vectors.len);
	vectors.vectY = (double*) malloc(sizeof(double) * vectors.len);
	
	// Собираем вектор x
	
	for (uint16_t i = 0; i < vectors.len; i++){	
		*(vectors.vectX + i) = *(summaryVect + i);	
	}
	
	// Собираем вектор y
	
	for (uint16_t i = 0; i < vectors.len; i++){
		*(vectors.vectY + i) = *(summaryVect + i + vectors.len);
	}
	
	free(summaryVect);
		
}

void getVectFromFile(char * file_name){
	
	FILE *file_in = fopen(file_name, "r");
	uint16_t read_pos = 0;
	
	double *tmpVect = (double*) malloc (sizeof(double) * 1);
	
	while (!feof(file_in)){
	
		fscanf(file_in, "%lf", tmpVect + read_pos++);
		tmpVect = realloc(tmpVect, sizeof(double) * (read_pos+1));
		
	}
	
	fclose(file_in);
	
	vectors.len = (read_pos / 2);
	getSplitVect(tmpVect);
}

void outVectConsole(){
	printf("Значения x: ");
	for (uint16_t i = 0; i < vectors.len; i++){
		printf("%lf", *((vectors.vectX) + i));
		i == (vectors.len - 1) ? printf("\n") : printf(" ");
	}
	
	printf("Значения y: ");	
	for (uint16_t i = 0; i < vectors.len; i++){
		printf("%lf", *((vectors.vectY) + i));
		i == (vectors.len - 1) ? printf("\n") : printf(" ");
	}
}
