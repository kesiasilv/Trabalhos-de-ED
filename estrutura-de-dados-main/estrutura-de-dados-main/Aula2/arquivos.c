#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{
    char Nome[50];
    int Quantidade;
    float Preco;

} Produto;

int main()
{
    FILE *fp;
    FILE *html;
    Produto X;
    float Total = 0.0;

    fp = fopen("dados.txt", "r");
    html = fopen("resultado.html", "w"); // "r" abre o arquivo para leitura
    if (fp == NULL || html == NULL)
    {
        printf("O arquivo nao pode ser aberto!\n");
        exit(1);
    }
    // Estilo
    fprintf(html, "<style> ");
    fprintf(html, "table {border-collapse: collapse;width: 100vw;} body {font-family: sans-serif;  margin: 10px} th, td {padding: 8px;text-align: left;border-bottom: 1px solid #DDD;} tr:hover {background-color: #D6EEEE;}");
    fprintf(html, "</style>\n");
    fprintf(html, "<h1>Tabela de Produtos</h1>");
    // Inicio da tabela
    fprintf(html, "<table>\n");
    // Thead
    fprintf(html, "<tr>\n");
    fprintf(html, "<th>Nome</th>");
    fprintf(html, "<th>Quantidade</th>");
    fprintf(html, "<th>Preço</th>");
    fprintf(html, "<th>Subtotal</th>");
    fprintf(html, "</tr>\n");

    while (fscanf(fp, "%s %d %f", X.Nome, &X.Quantidade, &X.Preco) != EOF)
    {
        float Subtotal = X.Quantidade * X.Preco;
        // Tbody
        fprintf(html, "<tr>\n");
        fprintf(html, "<td>%s</td>", X.Nome);
        fprintf(html, "<td>%d</td>", X.Quantidade);
        fprintf(html, "<td>%.2f</td>", X.Preco);
        fprintf(html, "<td>%.2f</td>", Subtotal);
        fprintf(html, "</tr>\n");

        Total = Total + Subtotal;
    }

    printf("Valor total: %.2f\n", Total);
    fprintf(html, "</table>\n");
    fprintf(html, "<p>O valor total é R$%.2f</p>", Total);
    fclose(fp);

    return 0;
}