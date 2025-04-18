#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

int compare(const void *a, const void *b) {
    Cidade *cidadeA = (Cidade *)a;
    Cidade *cidadeB = (Cidade *)b;
    return cidadeA->Posicao - cidadeB->Posicao;
}

Estrada *getEstrada(const char *nomeArquivo) { 
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    int comprimentoEstrada, numCidades;
    if (fscanf(file, "%d %d", &comprimentoEstrada, &numCidades) != 2) {
        printf("Erro ao ler o comprimento da estrada e o número de cidades.\n");
        fclose(file);
        return NULL;
    }

    if (comprimentoEstrada < 3 || comprimentoEstrada > 1000000 || numCidades < 2 || numCidades > 10000) {
        printf("Valores inválidos para o comprimento da estrada ou número de cidades.\n");
        fclose(file);
        return NULL;
    }

    Cidade *cidades = (Cidade *)malloc(numCidades * sizeof(Cidade));
    if (!cidades) {
        printf("Erro ao alocar memória para as cidades.\n");
        fclose(file);
        return NULL;
    }

    int i;
    for (i = 0; i < numCidades; i++) {
        if (fscanf(file, "%d %[^\n]", &cidades[i].Posicao, cidades[i].Nome) != 2) {
            printf("Erro ao ler as informações da cidade.\n");
            free(cidades); // Liberar memória antes de retornar
            fclose(file);
            return NULL;
        }
        if (cidades[i].Posicao <= 0 || cidades[i].Posicao >= comprimentoEstrada) {
            printf("Posição inválida para a cidade.\n");
            free(cidades); // Liberar memória antes de retornar
            fclose(file);
            return NULL;
        }
    }

    fclose(file);

    qsort(cidades, numCidades, sizeof(Cidade), compare);

    // Criar a estrutura Estrada e atribuir valores
    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    if (!estrada) {
        printf("Erro ao alocar memória para a estrutura Estrada.\n");
        free(cidades); // Liberar memória antes de retornar
        return NULL;
    }

    estrada->T = comprimentoEstrada;
    estrada->N = numCidades;
    estrada->C = cidades;

    return estrada;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return -1;
    }

    // Calcular a média das posições das cidades
    double mediaPosicoes = 0;
    int i;
    for (i = 0; i < estrada->N; i++) {
        mediaPosicoes += estrada->C[i].Posicao;
    }
    mediaPosicoes /= estrada->N;

    // Determinar a menor vizinhança
    double menorVizinhanca = mediaPosicoes < estrada->T - mediaPosicoes ? mediaPosicoes : estrada->T - mediaPosicoes;

    free(estrada->C);
    free(estrada);

    return menorVizinhanca;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return NULL;
    }

    // Calcular a média das posições das cidades
    double mediaPosicoes = 0;
    int i;
    for (i = 0; i < estrada->N; i++) {
        mediaPosicoes += estrada->C[i].Posicao;
    }
    mediaPosicoes /= estrada->N;

    // Determinar a cidade com menor vizinhança
    char *cidadeMenor = estrada->C[0].Nome;
    double menorDistancia = mediaPosicoes - estrada->C[0].Posicao;
    for (i = 1; i < estrada->N; i++) {
        double distancia = mediaPosicoes - estrada->C[i].Posicao;
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            cidadeMenor = estrada->C[i].Nome;
        }
    }

    free(estrada->C);
    free(estrada);

    return cidadeMenor;
    
}


int main() {
    const char *nomeArquivo = "teste01.txt"; // Nome do arquivo de entrada

    double menorVizinhanca = calcularMenorVizinhanca(nomeArquivo);
    if (menorVizinhanca < 0) {
        printf("Erro ao calcular a menor vizinhanca.\n");
        return 1;
    }

    printf("Menor vizinhanca encontrada: %.2f\n", menorVizinhanca);

    char *cidadeMenor = cidadeMenorVizinhanca(nomeArquivo);
    if (cidadeMenor == NULL) {
        printf("Erro ao determinar a cidade com menor vizinhanca.\n");
        return 1;
    }

    printf("Cidade com menor vizinhanca: %s\n", cidadeMenor);
    free(cidadeMenor);

    return 0;
}
