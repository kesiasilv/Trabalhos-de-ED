#include <stdio.h>

float soma_serie_harmonica(int N)
{
  float soma = 0;
  for (int i = 1; i <= N; i++)
  {
    soma += 1.0 / i;
  }
  return soma;
}

int main()
{
  int N;
  printf("Digite o valor de N: ");
  scanf("%d", &N);

  float resultado = soma_serie_harmonica(N);
  printf("A soma dos %d primeiros termos da serie harmonica e: %.2f\n", N, resultado);

  return 0;
}
