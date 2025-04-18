#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char minusculo();

int main()
{

  char letra = minusculo();
  printf("\n%c", letra);
  return 0;
}

char minusculo()
{
  char ch = getchar(); // Ler um caractere, apenas.
  if ((ch >= 'A') && (ch <= 'Z'))
    return (ch + 32);
  else
    return (ch);
}
