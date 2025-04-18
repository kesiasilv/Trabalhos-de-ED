#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct Pessoa
{
  char Nome[100];
  int Idade;
  float Altura;
  float Peso;
} Pessoa;

Pessoa CadastrarPessoa();
void ExibirPessoa(Pessoa X);
float CalcularIMC(Pessoa X);
void FazendoAniversario(Pessoa *X);
// void CadastrarPessoav2(Pessoa *X);

int main()
{
  Pessoa X = CadastrarPessoa();

  ExibirPessoa(X);

  FazendoAniversario(&X);

  ExibirPessoa(X);

  printf("O IMC de é igual à %.3f\n", CalcularIMC(X));

  return 0;
}

Pessoa CadastrarPessoa()
{

  Pessoa P;
  printf("Nome: ");
  fgets(P.Nome, 100, stdin);

  printf("Idade: ");
  scanf("%d", &P.Idade);

  printf("Altura: ");
  scanf("%f", &P.Altura);

  printf("Peso: ");
  scanf("%f", &P.Peso);

  return P;
}

void ExibirPessoa(Pessoa X)
{
  printf("%s %d %.2f %.2f\n", X.Nome, X.Idade, X.Altura, X.Peso);
}

float CalcularIMC(Pessoa X)
{
  float IMC = X.Peso / pow(X.Altura, 2);
  return (IMC);
}

void FazendoAniversario(Pessoa *X)
{
  X->Idade = X->Idade + 1;

  // Usando -> no lugar de . pois X é um ponteiro da struct
}