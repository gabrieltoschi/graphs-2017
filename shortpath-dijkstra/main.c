#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "mgraph.h"
#include "dijkstra.h"

int main(int argc, char *argv[]){
	int i, ct, current;
	int vertexQuant, edgeQuant;
	int edge1, edge2, cost;
	int *result, *path;
	MGraph *graph;

	// le numero de vertices e arestas
	scanf("%d%d", &vertexQuant, &edgeQuant);

	// cria o grafo
	graph = createGraphM(vertexQuant, true);

	// le as arestas e insere no grafo
	for (i = 0; i < edgeQuant; i++){
		scanf("%d%d%d", &edge1, &edge2, &cost);
		insertEdgeM(graph, edge1, edge2, cost);
	}

	// le as buscas e aplica Dijkstra
	while (!feof(stdin)){
		scanf("%d%d", &edge1, &edge2);
		if (!feof(stdin)){
			result = dijkstra(graph, edge1);

			path = (int *) malloc(sizeof(int));
			ct = 1;
			path[0] = edge2;
			current = edge2;

			// percorra a arvore criada pelo algoritmo
			while (current != NoEdge && current != edge1){
				path = (int *) realloc(path, sizeof(int) * (ct + 1));
				path[ct++] = result[current];
				current = result[current];
			}

			// caso ele tenha encontrado um caminho
			if (current == edge1){
				// imprima o caminho
				for (i = ct - 1; i >= 0; i--) printf("%d ", path[i]);
			}
			printf("\n");

			// desalocando memoria auxiliar
			free(path);
			free(result);
		}
	}

	destroyGraphM(graph);
}