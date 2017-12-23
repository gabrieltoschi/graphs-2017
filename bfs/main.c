#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "mgraph.h"
#include "BFS.h"

int main(int argc, char *argv[]){
	int i;
	int vertexQuant, edgeQuant;
	int edge1, edge2;
	int *BFSresult, *path;
	int ct, current;
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

	// le as buscas e aplica DFS
	while (!feof(stdin)){
		scanf("%d%d", &edge1, &edge2);
		if (!feof(stdin)){
			if (edge1 == edge2){
				// ja esta no vertice de destino
				printf("%d\n", edge1);
				continue;
			}

			BFSresult = BFS(graph, edge1);

			path = (int *) malloc(sizeof(int));
			ct = 1;
			path[0] = edge2;
			current = edge2;

			// percorra a arvore criada pelo DFS
			while (current != nil && current != edge1){
				path = (int *) realloc(path, sizeof(int) * (ct + 1));
				path[ct++] = BFSresult[current];
				current = BFSresult[current];
			}

			// caso ele tenha encontrado um caminho
			if (current == edge1){
				// imprima o caminho
				for (i = ct - 1; i >= 0; i--) printf("%d ", path[i]);
			}
			printf("\n");

			// desalocando memoria auxiliar
			free(path);
			free(BFSresult);
		}
	}

	// desalocando grafo
	destroyGraphM(graph);
}