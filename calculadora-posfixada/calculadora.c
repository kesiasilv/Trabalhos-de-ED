#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calculadora.h"

// Função auxiliar para verificar se um caractere é um operador
int ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Função para converter uma expressão pós-fixada em infixada
char *getFormaInFixa(char *Str) {
    static char resultado[512];
    char stack[100][512];
    int top = -1;

    char *token = strtok(Str, " ");
    while (token != NULL) {
        if (!ehOperador(token[0])) {
            strcpy(stack[++top], token);
        } else {
            char op2[512];
            char op1[512];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            sprintf(stack[++top], "(%s %c %s)", op1, token[0], op2);
        }
        token = strtok(NULL, " ");
    }
    strcpy(resultado, stack[top]);
    return resultado;
}

// Função para calcular o valor de uma expressão pós-fixada
float getValor(char *Str) {
    float stack[100];
    int top = -1;

    char *token = strtok(Str, " ");
    while (token != NULL) {
        if (!ehOperador(token[0])) {
            stack[++top] = atof(token);
        } else {
            float op2 = stack[top--];
            float op1 = stack[top--];
            switch (token[0]) {
                case '+': stack[++top] = op1 + op2; break;
                case '-': stack[++top] = op1 - op2; break;
                case '*': stack[++top] = op1 * op2; break;
                case '/': stack[++top] = op1 / op2; break;
                case '^': stack[++top] = powf(op1, op2); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return stack[top];
}
int main() {
    char posFixa[] = "53 23 + 8 2 - *";
    
    // Convertendo para a forma infixa
    char posFixaCopy1[512];
    strcpy(posFixaCopy1, posFixa);
    char *inFixa = getFormaInFixa(posFixaCopy1);
    
    // Calculando o valor da expressão
    char posFixaCopy2[512];
    strcpy(posFixaCopy2, posFixa);
    float valor = getValor(posFixaCopy2);
    
    printf("Forma infixada: %s\n", inFixa);
    printf("Valor da expressão: %.2f\n", valor);

    return 0;
}
