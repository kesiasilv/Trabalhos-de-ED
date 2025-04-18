#include <stdio.h>
int main(){
	float seg, dias, horas, minut;

	printf("Digite o valor em segundos: ");
	scanf("%f", &seg);

	minut= seg / 60;
	horas= minut / 60;
	dias= horas / 24 ;

	printf("Os %.0f segundos resultam em %.2f minutos, %.2f horas e %.2f Dias", seg, minut, horas, dias);
}