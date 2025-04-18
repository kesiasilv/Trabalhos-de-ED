#include <stdio.h>
#include <math.h>
int  main(){
	float resul, num1, num2, num3, num4;
	
	printf("Digite um numero positivo maior que zero: ");
	scanf("%f", &num1);

	resul = pow(num1, 2);
	num2= pow(num1, 3);
	num3= sqrt(num1);
	num4= cbrt(num1);

	printf("O numero digitado ao quadrado e: %.1f \n", resul);
	printf("O numero digitado ao cubo e: %.1f \n", num2);
	printf("A raiz quadrada do numero digitado e: %.1f \n", num3);
	printf("A raiz cubica do numero digitado e: %.1f \n", num4);
}