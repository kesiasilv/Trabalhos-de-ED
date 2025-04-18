#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
	char nome[50];
	int matricula;
	double nota[3];
	double media;
};

typedef struct Aluno Aluno;

void lerDadosAluno(struct Aluno Aluno[3]){
	int i;
	for(i = 0; i<3; i++){
		printf("=========Aluno %d=========\n", i + 1);
		printf("==========================\n");
		puts("\tNome: ");
		scanf("%50[^\n]s", &Aluno[i].nome);
		fflush(stdin);
		printf("\n");
		
		printf("Matricula: ");
		scanf("%d", &Aluno[i].matricula);
		printf("\n");
		double soma = 0;
		int n;
		for(n = 0; n<3; n++){
			printf("Nota: %d\n", n + 1);
			scanf("%lf", &Aluno[i].nota[n]);
			fflush(stdin);
			soma += Aluno[i].nota[n];
		}
		Aluno[i].media = soma / 3;
	}
}

void imprimeDadosAluno(struct Aluno Aluno[3]){
	int i;
	for(i = 0; i < 3; i++){
		printf("\n\n========Aluno %d:=======\n", i + 1);
		printf("nome: %s\n", Aluno[i].nome);
		printf("matricula: %d\n", Aluno[i].matricula);
		printf("media = %.2lf\n", Aluno[i].media);
		if(Aluno[i].media >= 5 && Aluno[i].media > 7){
			printf("\n-----Aprovado!-----\n");
		}else if(Aluno[i].media < 5){
			printf("\n-----Reprovado!----\n");
		}
	}

}

int main(){
	Aluno dados[3];
	lerDadosAluno(dados);
	system("cls");
	imprimeDadosAluno(dados);
}
