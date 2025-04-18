#include <stdio.h>
#include <stdlib.h>

#define ERRO -1

int Area(int Lado);

int main()
{
}

int Area(int Lado)
{
  int Q;
  if (Lado == 2 || Lado == 3 || Lado == 4 || Lado == 5)
  {

    Q = Lado * Lado;
  }
  else
  {
    return (ERRO);
  }
}