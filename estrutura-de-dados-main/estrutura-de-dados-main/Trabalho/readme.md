# Instruções

Este trabalho prático tem por finalidade a implementação, em C, de algoritmo para leitura e manipulação de dados formatados de um arquivo texto e deve ser realizado em grupo com até 3 (três) integrantes.

Observação:

Apenas 1 (um) integrante deve enviar o trabalho.

### Formato dos dados

No arquivo **DadosEntrada.cvs**, cada linha contém o nome, o telefone (com prefixo), o curso, e as notas que cada um dos alunos matriculados em uma universidade obteve durante um semestre. No exemplo a seguir, observe que os atributos da aluna Maria Oliveira são (555) 123-4567, Direito, 9.0 e 9.3 e estão separados por vírgula:

<p style="text-align: center; font-family: serif"><strong>Maria Oliveira,(555) 123-4567,Direito,9.0,9.3</strong></p>

### O que deve ser feito

O programa a ser construído deve ler dados de cada aluno, identificando o nome e as notas para, a seguir, determinar a nota média e a situação final do aluno (APROVADO, caso a nota média seja maior ou igual a 7.0 ou REPROVADO, caso a nota média seja menor do que 7.0). Por fim, deve ser gerado um arquivo chamado SituacaoFinal.cvs em que cada linha deverá ter o nome do aluno, a nota média com duas casas decimais e a situação do aluno. Por exemplo, para a aluna Maria Oliveira, cujas notas foram 9.0 e 9.3, deverá ser gravado no arquivo de saída:

<p style="text-align: center; font-family: serif"><strong>Maria Oliveira, 9.15, APROVADO</strong></p>

### Observações:

1. Este é um trabalho prático em grupo e vale 3 pontos.
2. Caso seja entregue com atraso, o valor total passará a ser, para n dias de atraso, 3,0 \* 0,9^n.
3. O trabalho deverá ser postado no AVA, em template próprio.
4. Todas as seções do template devem ser preenchidas.
5. Deve ser utilizada a formatação indicada no próprio arquivo template.
6. O código-fonte deve ser disponibilizado no Git e compartilhado com o professor.
7. Trabalhos iguais ou com seções iguais/parecidos terão nota 0.
8. Na biblioteca string.h existem funções para manipulação de strings que podem ser úteis.
