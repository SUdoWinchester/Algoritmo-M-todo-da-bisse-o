#include <stdio.h>
#include <math.h>

double powQueFunciona(double base, double expoente) {
	if(expoente > 0)
		return base * powQueFunciona(base, expoente-1);
	else
		return 1;
}

double f(double x) {
	return pow(M_E, x) - 4 * pow(x, 2);
}

double modulo(double x) {
	if(x < 0)
		return x * -1;
	else
		return x;
}

void main() {
	double a, b, precisao, finicio, meio, fmeio, raiz;
	int k, num;

	printf("Entre com o intervalo\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	printf("Entre com a precisao\n");
	scanf("%lf", &precisao);
	printf("Entre com numero maximo de interacoes\n");
	scanf("%d", &num);

	k = 0;

	if(modulo(b - a) > precisao) {
		while(modulo(b - a) > precisao && k < num) {
			k++;

			finicio = f(a);
			meio = (a + b)/2;
			fmeio = f(meio);

			if(finicio * fmeio < 0) {
				b = meio;
				raiz = b;
			} else {
				a = meio;
				raiz = a;
			}
		}
	}

	printf("Raiz = %lf\n", raiz);
	printf("Numero de interacoes necessaria = %d\n", k);
}