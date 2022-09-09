/*
Vitória Nazareth
09/06/2022
*/

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubblesort(int bubble[], int tamanho){
    int i, j, maior;
    for(j = tamanho-1; j >= 1; j--){  //for para n-1 repetições do vetor
        for(i = 0; i < tamanho; i++){ //for para repetição da iteração
            if(bubble[i] > bubble[i+1]){
                maior = bubble[i];
                bubble[i] = bubble[i+1];
                bubble[i+1] = maior;
            }
        }

    }
}

void troca(int elementos[], int i, int j)
{
	int aux = elementos[i];
	elementos[i] = elementos[j];
	elementos[j] = aux;
}

int particiona(int quick[], int start, int end)
{
	int pivot = quick[end];
	int varredor; //varre o vetor
	int gerente = start; //gerencia as trocas
	
	for(varredor = start; varredor < end; varredor++){
		if(quick[varredor] <= pivot){
			troca(quick, varredor, gerente);
		    gerente++;
		}
	}
	
 //põe o pivot no lugar correto
	troca(quick, gerente, end);
	
	//devolve a posição atual do pivot
	return gerente;
}

void quicksort(int vetor[], int comeco, int fim)
{
	if(comeco < fim)
	{
		int posi_pivo = particiona(vetor, comeco, fim); //recebe a posição final do pivot
		quicksort(vetor, comeco, posi_pivo - 1);  //ordena esquerda
		quicksort(vetor, posi_pivo + 1, fim); //ordena direita
	}
  
}

void Une_merged(int vetor[], int auxiliar[], int i, int m, int f) {
  int z;
  int ivetor = i, iaux = m + 1;
  
  for (z = i; z <= f; z++) auxiliar[z] = vetor[z];  //copia do vetor principal para o auxiliar
  z = i;  //reseta z
  
//compara e ordena os valores no vetor principal
  while (ivetor <= m && iaux <= f) {
    if (auxiliar[ivetor] <= auxiliar[iaux]) vetor[z++] = auxiliar[ivetor++];
    else vetor[z++] = auxiliar[iaux++];
  }

  while (ivetor <= m) vetor[z++] = auxiliar[ivetor++];  //copia o restante dos valores da esquerda
  while (iaux <= f) vetor[z++] = auxiliar[iaux++];  //copia o restante dos valores da direita
  
}

void mergesort(int vetor[], int auxiliar[], int i, int f){
    int metade = (i + (f)) / 2;

    if (i < f){ 
        mergesort(vetor, auxiliar, i, metade);
        mergesort(vetor, auxiliar, metade + 1, f); 
    }
    
    if (vetor[metade] <= vetor[metade + 1]) return; //vetor ordenado nessa condição

    Une_merged(vetor, auxiliar, i, metade, f);
}

void auxiliar(int vetor[], int tamanho) {
  int *auxiliar = malloc(sizeof(int) * tamanho);  //aloca espaço para um vetor auxiliar
  mergesort(vetor, auxiliar, 0, tamanho - 1);
  free(auxiliar);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    //clock_t = tempo;
    int valores, print, t_vetor, posi_flag;
//varre o vetor de argumentos 
    for(int k = 0; k < argc; k++){
        if(strcmp(argv[k], "-n") == 0){
            t_vetor = atoi(argv[k+1]);
        }
        else if(strcmp(argv[k], "-m") == 0){
            posi_flag = k;
        }
        else if(strcmp(argv[k], "-q") == 0){
            posi_flag = k;
        }
    }
    
    int inicio = 0;
    int final = t_vetor -1;
    
    t_vetor = 10;
    int *vetor = malloc(t_vetor * sizeof(int));
    for(valores = 0; valores < t_vetor; valores++) vetor[valores] = rand() % 100;
    
//vetor original
    for(print = 0; print < t_vetor; print++){
        printf("%d ", vetor[print]);
    }
    printf("\n");
    
    if(argc == 4){
        if(strcmp(argv[posi_flag], "-m") == 0) {
            printf("MergeSort Selecionado -> \n");
            //tempo = clock();
            auxiliar(vetor, t_vetor);
            //tempo = clock() - tempo;
            
        }
        else if(strcmp(argv[posi_flag], "-q") == 0){
            printf("QuickSort Selecionado -> \n");
            int posi_pivo = rand() % final;    //gera uma posição aleatória para o pivot
            troca(vetor, posi_pivo, final);
            //tempo = clock();    //começa contar o tempo
            quicksort(vetor, inicio, final);
            //tempo = clock() - tempo;    //termina de contar o tempo
        }
    }
    else if (argc = 3){
        printf("BubbleSort Selecionado -> \n");
        //tempo = clock();//começa a contar
        bubblesort(vetor, t_vetor);//chama a função
        //tempo = clock() - tempo;//tempo final - tempo inicial
    }
    
    //double total = ((double)tempo)/((CLOCKS_PER_SEC/1000));
    for(print = 0; print < t_vetor; print++){
        printf("%d ", vetor[print]);
    }
    
    free(vetor);
    return 0;
}