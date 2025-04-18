#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  float X;
  float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C)
{
  // Calcula o determinante para obter a área do triângulo
  float det = A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y);
  return fabs(det) / 2.0; // Retorna o valor absoluto do determinante dividido por 2
}

int main()
{
  FILE *entrada;
  int numVertices, i;
  Ponto *vertices;

  // Abre o arquivo
  entrada = fopen("area.txt", "r");
  if (entrada == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Lê o número de vértices
  fscanf(entrada, "%d", &numVertices);

  // Aloca memória para armazenar os vértices
  vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
  if (vertices == NULL)
  {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  // Lê os vértices do arquivo
  for (i = 0; i < numVertices; i++)
  {
    fscanf(entrada, "%f %f", &vertices[i].X, &vertices[i].Y);
  }

  // Fecha o arquivo
  fclose(entrada);

  // Calcula a área do polígono dividindo-o em triângulos
  float areaPoligono = 0;
  for (i = 1; i < numVertices - 1; i++)
  {
    areaPoligono += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
  }

  // Imprime a área do polígono
  printf("A área do polígono é %.2f\n", areaPoligono);

  // Libera a memória alocada
  free(vertices);

  return 0;
}
