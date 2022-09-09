Trabalhos de Estrutura de dados - Professor Claudson Bornstein 
Programas implementados durante 2022.1

1º - Ordenadores
Executa três diferentes algoritmos de ordenação de acordo com a entrada do usuário.
A flag '-m' executa o algoritmo Merge sort, a flag '-q' executa o Quick sort e a entrada
vazia (sem flags) executa o Bubble sort.
As funções 'CLOCK()'comentadas servem para calcular o tempo de execução de cada algoritmo e
exibi-los ao final, junto com o vetor aleatório ordenado.
Exemplos de entrada: x faz referencia ao inteiro, tamanho do vetor a ser ordenado.
	-n x -m; - merge
	-q -n x; - quick
	 -n x; - bubble

2º - Calcula_Expressao
Executa um cálculo de expressão matemática através do uso de pilhas. A expressão é calculada
da direita para a esquerda. Usa-se '/' para divisão, '-' para subtração, '+' para soma e '*'
para multiplicação.
Exemplos:
	Entrada - 4+3-6; Saída - 7; 
	Entrada - 8/7*5-6; Saída - -1;
	Entrada - 8+9-7/7-14; Saída - 0; 

3º - Ord_Topológica
Executa a ordenação de vértices de um grafo através do método de ordenação topológica
utilizando busca em profundidade. Ele gera vértices representando as conexões
no grafo de exemplo, retorna a ordem das visitas (de acordo com o grafo de exemplo) e a
ordenação correta dos vértices.
Exemplos:
	Segue um grafo de exemplo pronto dentro do código, basta altera-lo.
