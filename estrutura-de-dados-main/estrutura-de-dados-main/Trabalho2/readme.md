# Trabalho prático número 02

### 1. Calculando Areas

Calcular a área de polígonos é importante em diversos contextos, especialmente na cartografia e no processo
de elaboração de mapas, dada a possibilidade de se representar, no espaço $ℝ2$, a superfície curva do globo
terrestre. A título de exemplo vê-se, na figura, um mapa no qual foi destacada uma região poligonal, ou seja,
cujos lados são formados por segmentos de reta.

Para determinar a área dessa região, uma possibilidade é, a partir de um vértice, traçar diagonais desse
polígono para dividi-lo em triângulos. Assim, a área a ser determinada é equivalente ao somatório das áreas
dos triângulos obtidos a partir das diagonais traçadas. Veja, a seguir, que a região sombreada em cor azul foi
dividida em 8 triângulos, o que nos permite estabelecer a relação:

$$𝐴(𝑝𝑜𝑙í𝑔𝑜𝑛𝑜) = 𝐴1 + 𝐴2 + 𝐴3 + ⋯ + 𝐴8$$

em que cada $𝐴𝑖$ é área de um dos triângulos que compõe o polígono azul.

### 2. O que deve ser feito

Escreva, em C, um algoritmo para determinar a área de uma região poligonal cujos vértices estão organizados
em um arquivo texto. Nesse arquivo, a primeira linha mostra o número de lados (ou vértices) do polígono e
cada uma das linhas a seguir trazem as coordenadas x e y desses vértices separadas por um espaço. Por
exemplo, caso o polígono tenha vértices (1, 2), (3, 8) e (5, 1), o arquivo de entrada terá o seguinte aspecto:

Como saída, o programa deve informar a área desse polígono em uma mensagem exibida no painel terminal
ou no prompt de comando. Assim, no caso do triângulo indicado acima, a saída deveria ser: “**A área do
polígono é 13**”.

#### Atenção

> No desenvolvimento deste trabalho prático, devem ser observadas as seguintes restrições:

1. Deve ser usado a struct Ponto:

```c
typedef struct{
  float X;
  float Y;
} Ponto;
```

2. Novas structs podem ser implementadas (e explicadas como comentários);
3. Para criar exemplos de polígonos de teste, use o software [Geogebra](www.geogebra.org);
4. O código-fonte deve ser modularizado.
5. Deve ser implementada a função float AreaTriangulo (Ponto A, Ponto B, Ponto C);
6. Para polígonos de 3 ou mais lados, a área deve ser calculada a partir da decomposição em triângulos.
7. Devem ser enviados o código-fonte em arquivo.c
8. Não envie arquivos executáveis.
9. Para cada dia de atraso, sua nota será reduzida de 10%;
10. Esta atividade vale 3,0 pontos;
11. Este trabalho é individual.

### 3. A área do triângulo

Sejam $A(x_A, y_A)$, $B(x_B,y_B)$ e $C(x_C,y_C)$ vértices do triângulo $ABC$

A área do triângulo $ABC$ é igual a $\frac{Det}{2}$ em que $Det =$

$$
\left(\begin{array}{cc}
x_a & y_a & 1\\
x_b & y_b & 1\\
x_c & y_c & 1
\end{array}\right)
$$

Por exemplo, no caso do triângulo de vértices A = (1, 2), B = (3, 8) e C = (5, 1), a área seria igual a 13, uma vez
que o determinante tem valor absoluto 26 e tem cálculos detalhados a seguir:

$$
Det = \left(\begin{array}{cc}
x_a & y_a & 1 & x_a & y_a \\
x_b & y_b & 1 & x_b & y_b\\
x_c & y_c & 1 & x_c & y_c\\
\end{array}\right) =
$$

$$
\left(\begin{array}{cc}
1 & 2 & 1 & 1 & 2 \\
3 & 8 & 1 & 3 & 8\\
5 & 1 & 1 & 5 & 1\\
\end{array}\right) = 8 + 10 + 3 - 40 - 1 - 6  = -26
$$
