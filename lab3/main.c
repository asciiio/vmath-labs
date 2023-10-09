#include "deps/vector.h"
#include "least.h"
int main(int argc, char **argv){
	vect_t vectors;
	uint16_t degree;
	double *otv;
	
	vectRead(&vectors, argv[1]);
	
	printf("Наборы точек считаны - \"%s\", введите степень полинома: ", argv[1]);
	scanf("%hd", &degree);
	degree < vectors.len ? (otv = least(vectors, degree)) : exit(-3);
	otv = least(vectors, degree);
	
	for (int i = 0; i < degree + 1; i++){
		printf("%lf ", *(otv+i));
	}
	return 0;
}
