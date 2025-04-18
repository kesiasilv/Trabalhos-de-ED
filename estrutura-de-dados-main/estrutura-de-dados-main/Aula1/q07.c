#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n = 12;
  printf("Esse e o numero: %d\n", g(n));
  return 0;
}

int g(int n)
{
  if (n == 0)
  {
    return n = -1;
  }
  else if (n > 0)
  {
    return g(n - 1) + 6;
  }
}