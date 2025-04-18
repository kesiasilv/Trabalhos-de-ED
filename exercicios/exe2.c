#include <stdio.h>
#include <math.h>
int main(){
	float x1, x2, y1, y2, d;

	printf("Digite o Ponto 1, X e Y nesta ordem: ");
	scanf("%f %f", &x1, &y1);
	printf("Digite o Ponto 2, X e Y nesta ordem: ");
	scanf("%f %f", &x2, &y2);

	d= sqrt(pow(x1- x2, 2) + pow(y1-y2, 2));

	printf("A distancia dos Pontos e: %.2f", d);

	}