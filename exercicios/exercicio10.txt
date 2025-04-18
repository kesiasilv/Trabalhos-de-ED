#include <stdio.h>
int main() {
	float n1, n2, n3, p1, p2, p3, m;

	printf("Digite as suas notas N1, N2, N3 separados por virgula:");
	scanf("%f, %f, %f", &n1, &n2, &n3);

	printf("Digite seus pesos P1, P2, P3 separdos por virgula:");
	scanf("%f, %f, %f", &p1, &p2, &p3);
	
	m=(n1*p1) + (n2*p2) + (n3*p3)/(p1+p2+p3);

	printf("Sua media e: %.1f", m);
}