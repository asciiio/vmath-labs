#include <stdio.h>
#include <math.h>

int n = 20;
double epsilon = 0.00001;

double function(double x){
	return fabs(logl(x));
}

double leftRect(double down, double up, int n){			// Метод левых треугольников

	double h = (double)((up - down) / n);			// Шаг интегрирования
	double x = down;							// Начальная точка
	double S = 0.0;								// Интегральная сумма

	for (int i = 0; i <= n-1; i++){				// Формула
		S += function(x);
		x += h;
	}
	return S*h;
}

double rightRect(double down, double up, int n){		// Метод правых треугольников

	double h = (double)((up - down) / n);
	double x = down+h;
	double S = 0.0;

	for (int i = 1; i <= n; i++){				// Формула
		S += function(x);
		x += h;
	}
	return S*h;
}

double trapMethod(double down, double up, int n) {		// Метод трапеций

    double h = (double)((up - down) / n);
    double x = down;
    double S = 0.0;

    S += ((function(down) + function(up)) / 2);

    for (int i = 1; i <= n-1; i++) {
        x += h;
        S += function(x);
    }

    return S*h;
}

double simpsonMethod(double down, double up, int n){	// Метод Симпсона

	double h = (double) ((up - down) / n);	// Вычисляем длину шага
	double x = down;						// Начальное значение x
	double S = 0.0;							// интегральная сумма

	S += (function(down) + function(up));	// тут мы учли концы отрезка

	for (int i = 1; i <= n-1; i++){			// Все точки кроме концов отрезка
		x += h;
		if ((i % 2) == 0){	// Вхождение данных точек с соответсвующими весовыми кф
			S += 2*function(x);
		}

		else {
			S += 4*function(x);
		}
	}
	return S*2*h/6;
}

int main(){

	const double exp = 2.71828;

	double prevSum = simpsonMethod(1/exp, exp, n), currentSum;

	for (int i = 2;; i+=2){
		n += i;
		currentSum = simpsonMethod(1/exp, exp, n);

		if (fabs(prevSum-currentSum) > epsilon){
			prevSum = currentSum;
		}
		else {
			printf("Result: %lf, n = %d.\n", currentSum, n);
			break;
		}
	}
}
