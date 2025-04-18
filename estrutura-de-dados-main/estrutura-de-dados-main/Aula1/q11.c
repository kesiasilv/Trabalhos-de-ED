#include <stdio.h>

int mdc(int a, int b)
{
  if (b == 0)
  {
    return a;
  }
  else
  {
    return mdc(b, a % b);
  }

  return 0;
}

int main()
{
  int num1, num2;
  printf("Digite dois números inteiros: ");
  scanf("%d %d", &num1, &num2);

  int maior = mdc(num1, num2);
  printf("O MDC de %d e %d é: %d\n", num1, num2, maior);

  return 0;
}