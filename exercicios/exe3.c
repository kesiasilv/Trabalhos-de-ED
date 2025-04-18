#include <stdio.h>
int main(){
	float sal, percn;

	printf("Digite seu salario: ");
	scanf("%f", &sal);
	printf("Digite o valor do aumento em decimal: ");
	scanf("%f", &percn);

	sal = (sal * percn) + sal;
	
	printf("O seu aumento de %.2f gera o novo salario de: %.2f", percn, sal);
}
	