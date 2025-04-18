#include <stdio.h>
int main(){
	int num;
	
	printf("Digite o numero de 5 algarismos positivo: ");
	scanf("%d", &num);

	printf("%d   %d   %d   %d   %d", (num/ 10000)% 10, (num/1000)% 10, (num/100)% 10, (num/10)% 10, num % 10);
}