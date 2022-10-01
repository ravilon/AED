# LinguagemC_AED
Repositório de estudos da dsciplina de Algoritmos e Estrutura de Dados

## Aluno: Rávilon Aguiar Dos Santos
### Link para documento com identação utilizada : https://fabiensanglard.net/fd_proxy/doom3/CodeStyleConventions.pdf
====================================================================================================================
#Atividade Avaliativa 26/08 em: AtividadeAvaliativa_01/exercicio-ras.c

Faça um programa que solicita do usuário uma série de números, cada número pode ser um
int, float ou double. Antes de solicitar o número pergunte qual tipo de dado o usuário vai entrar.
Todos os números entrados devem ser armazenados num buffer único. Esse buffer deve ter tamanho
dinâmico e não deve desperdiçar memória, por exemplo, alocar sempre espaço para um double
quando o usuário inserir um int ou float.
Você não deve solicitar para o usuário quantos números ele deseja entrar, na escolha do tipo
de dados coloque uma opção para parar a entrada da série de números. Após isso você deve imprimir
todos os números do buffer, primeiro toda a série em sequência depois novamente, mas primeiro os
ints seguido dos floats e doubles

Video explicando em: https://drive.google.com/file/d/1EbHh6i4ilDELiXD9-DEEVtQy3TtWBSB2/view?usp=sharing

Funcionando - TUDO

=====================================================================================================================
#Atividade Avaliativa 23/09 em: AtividadeAvaliativa_02/AtividadeAvaliativa02.c

Fazer um programa que testa se uma sequência de caracteres fornecida pelo
usuário é um palíndromo, ou seja, é uma palavra cuja primeira metade é
simétrica à segunda metade. Veja os exemplos:
AABCCBAA
-
sim
ADDFDDA
-
sim
ABFFBB
-
não
O usuário digita uma letra e tecla enter até que ele digite x e enter para
terminar a sequência.
Implemente a função POP e PUSH de pilha e resolva o problema com elas. No
vídeo demonstre pelo menos 4 casos de sim e 4 casos de não.

Video Explicando: 

https://drive.google.com/file/d/1APaTvsHWxxVMtvmYzlRCvc-rn4kRfc7U/view?usp=sharing

Funcionando 50%
=========================================================================================================================
Trabalho 

•Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Não pode usar struct em todo o programa.
Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
Implementar a base de dados da agenda usando lista duplamente ligada
Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

Video Explicando:


