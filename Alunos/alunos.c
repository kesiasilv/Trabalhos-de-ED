#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char Nome[50];
  char Numero[20];
  char Curso[20];
  float Nota1, Nota2, Media;
  char Situacao1;
} Aluno;

void calcularMedia(float nota1, float nota2, float *media, char *situacao)
{
  *media = (nota1 + nota2) / 2.0;
  *situacao = (*media >= 7.0) ? 'A' : 'R';
}

int main()
{
  FILE *entrada, *saida;
  Aluno X;
  char Situacao2[10];
  char Aprovado[] = "APROVADO";
  char Reprovado[] = "REPROVADO";

  entrada = fopen("DadosEntrada.csv", "r"); // "r" abre o arquivo para leitura
  saida = fopen("SituacaoFinal.csv", "w");  // "w" abre o arquivo para a escrita
  // Mensagem de erro
  if (entrada == NULL || saida == NULL)
  {
    printf("O arquivo nao pode ser aberto!\n");
    exit(1);
  }
  // Descartar a primeira linha do arquivo de entrada
  fscanf(entrada, "%*[^\n]");
  // Lê e descarta o caractere de nova linha
  fgetc(entrada);
  // Escrever o cabeçalho no arquivo de saída
  fprintf(saida, "Nome,Media,Situacao\n");
  // Ler DadosEntrada e escrever SituacaoFinal
  while (fscanf(entrada, "%[^,],(%[^)]) %*1[^(] %*[^,],%[^,],%f,%f", X.Nome, X.Numero, X.Curso, &X.Nota1, &X.Nota2) !=
         EOF)
  {
    calcularMedia(X.Nota1, X.Nota2, &X.Media, &X.Situacao1);
    // Fazendo a copia da string situcação
    if (X.Situacao1 == 'A')
    {
      strcpy(Situacao2, Aprovado);
    }
    else
    {
      strcpy(Situacao2, Reprovado);
    }
    fprintf(saida, "%s,%.2f,%s", X.Nome, X.Media, Situacao2);
  }

  printf("Terminado!\n");
  // Fechar os arquivos
  fclose(entrada);
  fclose(saida);

  return 0;
}
