#include <stdio.h>

int main(){
	
	char conteudo[10];
	
	printf("digite algo (gets): \n");
	gets(conteudo);
	fflush(stdin);
	
	puts("resultado:");
	puts(conteudo);
	puts("");
}
