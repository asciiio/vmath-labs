#include "vector.h"

static FILE *rstream;

void vectRead(vect_t *dst, char *src){
	if (src != NULL){
		rstream = fopen (src, "r");
		if (rstream == NULL){
			exit(-2);
		}
	}
	else exit(-1);
	
	double *tmp = (double*) malloc(sizeof(double));
	uint16_t elms = 0;
	
	while (!feof(rstream)){
		fscanf(rstream, "%lf", tmp + elms++);
		tmp = realloc(tmp, sizeof(double) * (1+elms));
	}
	
	dst->len = (elms/2);
	
	dst->vectX = (double*) malloc (sizeof(double) * dst->len);
	dst->vectY = (double*) malloc (sizeof(double) * dst->len);

	for (int i = 0; i < elms - 1; i++){
		if (i < dst->len) {
			*(dst->vectX + i) = *(tmp + i);
		}
		
		else {
			*(dst->vectY + i - dst->len) = *(tmp + i);
		}
	}
	
	free(tmp);
}

void vectWrite(vect_t src){	
	for (int i = 0; i < 2; i++){	
		for (int j = 0; j<src.len; j++){
			i == 0 ? printf("%lf ", *(src.vectX+j)) : printf("%lf ", *(src.vectY+j));
		}
		printf("\n");
	}
}

