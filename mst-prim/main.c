#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "mgraph.h"
#include "MST.h"

int main(int argc, char *argv[]){
	int i;
	int vertexQuant, edgeQuant;
	int edge1, edge2, cost;
	int *MSTpred, *MSTorder;
	MGraph *graph;

	// le numero de vertices e arestas
	scanf("%d%d", &vertexQuant, &edgeQuant);

	// cria o grafo
	graph = createGraphM(vertexQuant, false);

	// le as arestas e insere no grafo
	for (i = 0; i < edgeQuant; i++){
		scanf("%d%d%d", &edge1, &edge2, &cost);
		insertEdgeM(graph, edge1, edge2, cost);
	}

	// roda o algoritmo de PRIM
	MSTpred = MST(graph, 0, &MSTorder);

	// imprimindo arestas da MST na ordem
	for (i = 1; i < vertexQuant; i++){
		edge1 = MSTpred[MSTorder[i]];
		edge2 = MSTorder[i];
		if (edge2 < edge1){
			cost = edge1;
			edge1 = edge2;
			edge2 = cost;
		}
		printf("(%d,%d) ", edge1, edge2);
	}
	printf("\n");

	// desalocando memoria
	free(MSTpred);
	free(MSTorder);
	destroyGraphM(graph);
}