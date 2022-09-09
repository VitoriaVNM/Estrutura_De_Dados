#include <stdio.h>
#include <stdlib.h>

/*  Nome:Vitória Nazareth
    DRE: 121076766
    Ciência da Computação
    3º período
*/


typedef struct grafo Grafo;

struct grafo{
    int ponderado;
    int nmr_vertice;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *gr;

Grafo *cria_grafo(int nmr_vertice, int grau_max, int ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo)); //aloca espaço pro grafo
    if(gr != NULL){
        int i;
        gr->nmr_vertice = nmr_vertice;
        gr->grau_max = grau_max;
        gr->ponderado = ponderado;
        gr->grau = (int*) calloc(sizeof(int), nmr_vertice); //aloca espaço para os vertices
        gr->arestas = (int**) malloc(sizeof(int*)*nmr_vertice); //aloca espaço para as adjacencias
        for(i = 0; i< nmr_vertice; i++){
            gr->arestas[i] = (int*) malloc(sizeof(int)*grau_max);
        }
    }
    return gr;
}

void libera_grafo(Grafo *gr){
    if(gr != NULL){
        int i;
        //libera cada adjacencia e dps toda a lista
        for(i = 0; i < gr->nmr_vertice; i++) free(gr->arestas[i]);
        free(gr->arestas);
        
        //libera cada peso e dps toda a lista
        if(gr->ponderado){
            for(i = 0; i < gr->nmr_vertice; i++) free(gr->pesos[i]);
            free(gr->pesos);
        }
        //libera o tamanho do grafo e o grafo
        free(gr->grau);
        free(gr);
    }
}

int insere_aresta(Grafo *gr, int origem, int destino, int digrafo){
    if(gr == NULL) return 0;
//verifica se vertice existe
    if(origem < 0 || origem >= gr->nmr_vertice) return 0;
    if(destino < 0 || destino >= gr->nmr_vertice) return 0;
//aloca o destino na lista de adjacencias da aresta origem
    gr->arestas[origem] [gr->grau[origem]] = destino;
    gr->grau[origem]++;
//se não for digrafo
    if(digrafo == 0) insere_aresta(gr, destino, origem, 1);
    return 1;
}

/*int remove_aresta(Grafo *gr, int origem, int destino, int digrafo){
    if(gr == NULL) return 0;
//verifica se vertice existe
    if(origem < 0 || origem >= gr->nmr_vertice) return 0;
    if(destino < 0 || destino >= gr->nmr_vertice) return 0;
    
    int i = 0;
    while( i < gr->grau[origem] && gr->arestas[origem] [i] != destino){
        i++;
    }
    if(i == gr->grau[origem]) return 0;
    gr->grau[origem]--;
    gr->arestas[origem] [i] = gr->arestas[origem] [gr->grau[origem]];
    if(digrafo ==0) remove_aresta(gr, destino, origem, 1);
    return 1;
}*/

//calcula os graus de cada vertice
void busca_profundidade(Grafo *gr, int inicial, int *visitado, int count){
    int i;
    visitado[inicial] = count;
    for(i = 0; i < gr->grau[inicial]; i++){
        if(!visitado[gr->arestas[inicial] [i]]){
            busca_profundidade(gr, gr->arestas[inicial] [i], visitado, count+1);
        }
    }
}

void imprime_ordem(int *visitado){
    int i, j;
    int ordem[5];
    for(i = 0; i < gr->nmr_vertice; i++) ordem[i] = i;
    //imprime ordem de visita dos vertices
    printf("Ordem de visita dos vertices: ");
    for(i = 0; i < gr->nmr_vertice; i++) printf("%d ", visitado[i]);
    printf("\n");
    //imprime o vertice na ordem correta
    printf("Vertices ordenados: ");
    for(i = 1; i < gr->nmr_vertice + 1; i++){
        for(j = 0; j < gr->nmr_vertice; j++){
            if(i == visitado[j]) printf("%d ", ordem[j]);
        }
    }
}

void ordena_topologica(Grafo *gr, int inicial, int *visitado){
    int i, count = 1;
    for(i = 0; i < gr->nmr_vertice; i++) visitado[i] = 0;
    busca_profundidade(gr, inicial, visitado, count);
    imprime_ordem(visitado);
}

int main()
{
    int digrafo = 1;
//iniciando grafo de exemplo
    gr = cria_grafo(5, 5, 0);
    insere_aresta(gr, 0, 2, digrafo);
    insere_aresta(gr, 1, 3, digrafo);
    insere_aresta(gr, 1, 2, digrafo);
    insere_aresta(gr, 2, 4, digrafo);
    insere_aresta(gr, 3, 1, digrafo);
    insere_aresta(gr, 4, 1, digrafo);

    int visita[5]; //vertices a serem visitados
    ordena_topologica(gr, 0, visita); //grafo, vertice inicial, vetor de visita
    libera_grafo(gr); //destroi grafo
    
    return 0;
}