#include <stdio.h>
int main(){
	float pesok, quantg, resulg, resulcat, resto;
	
	printf("Digite o valor em quilos do saco de Racao: ");
	scanf("%f", &pesok);
	printf("Digite a quantidade diaria de Racao fornecida para cada gato em gramas: ");
	scanf("%f", &quantg);

	resulg= pesok * 1000;
	resulcat= (quantg * 2) * 5;
	resto= resulg - resulcat;

	printf("Restara %.1f gramas ou %.1f kilos apos 5 dias", resto, resto / 1000);
}