#include <stdio.h>
#include <math.h>
int main(){
	float sal, taxa, tempo, rendimento, juross, jcomposto;

	printf("Digite o seu salario: ");
	scanf("%f", &sal);
	printf("Digite seu tempo em meses: ");
	scanf("%f", &tempo);
	printf("Digite a taxa de juros em decimal: ");
	scanf("%f", &taxa);

	juross= taxa * sal * tempo;	
	rendimento= sal + juross;
	jcomposto = sal * pow((1 + taxa), tempo);
	

	printf("O seu salario de %.2f com juros de %.2f gera um rendimento de: %.2f \n",sal, taxa, rendimento);
	printf("O seu salario total depois do rendimento e: %.2f", jcomposto);
}
	