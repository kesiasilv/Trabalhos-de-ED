#include <stdio.h>

int main()
{
  int n;
  printf("Coloque sua nota: ");
  scanf("%d", &n);
  nota(n);
  return 0;
}

void nota(int n)
{
  if (n <= 100 && n >= 90)
  {
    return printf("Excelente!\n");
  }
  else if (n <= 89 && n >= 80)
  {
    return printf("Otimo!\n");
  }
  else if (n <= 79 && n >= 70)
  {
    return printf("Bom!\n");
  }
  else if (n <= 69 && n >= 60)
  {
    return printf("Regular!\n");
  }
  else if (n <= 59 && n >= 50)
  {
    return printf("Fraco!\n");
  }
  else
  {
    return printf("Insuficiente!\n");
  }
}