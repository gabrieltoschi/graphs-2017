#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "mgraph.h"
#include "DFS.h"

void bubbleSortIndexDesc(int *index, int *data, int n){
   int i, j, aux;

   for(i = 0; i < n-1; i++){
      for(j = 0; j < n-i-1; j++){
         if (data[index[j]] < data[index[j+1]]){          
         	aux = index[j];
         	index[j] = index[j+1];
         	index[j+1] = aux;
         }
      } 
   }
}

int main(int argc, char *argv[]){
	int i;
	int vertexQuant, edgeQuant;
	int edge1, edge2;
	int *DFSresult, *DFStime, *index;
	MGraph *graph;

	// le numero de vertices e arestas
	scanf("%d%d", &vertexQuant, &edgeQuant);

	// cria o grafo
	graph = createGraphM(vertexQuant, true);

	// le as arestas e insere no grafo
	for (i = 0; i < edgeQuant; i++){
		scanf("%d%d", &edge1, &edge2);
		insertEdgeM(graph, edge1, edge2, 1);
	}

	// rodando DFS
	DFSresult = DFS(graph, &DFStime);

	// criando vetores de indice
	index = (int *) malloc(sizeof(int) * vertexQuant);
	for (i = 0; i < vertexQuant; i++) index[i] = i;

	// ordenando vetor de indices de acordo com as timestamps do DFS
	bubbleSortIndexDesc(index, DFStime, vertexQuant);

	// mostrar a ordenação topologica na tela
	for (i = 0; i < vertexQuant; i++)
		printf("%d ", index[i]);
	printf("\n");

	// desalocando grafo
	destroyGraphM(graph);

	// desalocando vetores auxiliares
	free(DFSresult);
	free(DFStime);
	free(index);
}