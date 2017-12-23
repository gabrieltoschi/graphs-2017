#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "mgraph.h"
#include "lgraph.h"
#include "simplelist.h"

void runMatrixGraph(char dig){
	int vertexNum, edgeNum;
	int v1, v2, value;
	int i;
	char cmd1, cmd2;

	// ler numero de vertices e arestas
	scanf("%d %d\n", &vertexNum, &edgeNum);

	// criar grafo
	MGraph *g = createGraphM(vertexNum, dig == 'D' ? true : false);

	// ler arestas e inserir no grafo
	for (i = 0; i < edgeNum; i++){
		scanf("%d %d %d\n", &v1, &v2, &value);
		insertEdgeM(g, v1, v2, value);
	}

	// ler comandos
	while(!feof(stdin)){
		cmd1 = fgetc(stdin);
		if (!feof(stdin)){
			cmd2 = fgetc(stdin);

			// decodificar comando
			// IG = imprimir grafo
			if (cmd1 == 'I' && cmd2 == 'G'){
				cmd1 = fgetc(stdin); // limpar buffer
				printGraphM(g);
				continue;
			} 

			// VA = vertices adjacentes
			if (cmd1 == 'V' && cmd2 == 'A'){
				scanf("%d\n", &v1);
				getAdjacencyM(g, v1);
				continue;
			} 

			// AA = adicionar arestas
			if (cmd1 == 'A' && cmd2 == 'A'){
				scanf("%d %d %d\n", &v1, &v2, &value);
				insertEdgeM(g, v1, v2, value);
				continue;
			}

			// RA = remover arestas
			if (cmd1 == 'R' && cmd2 == 'A'){
				scanf("%d %d\n", &v1, &v2);
				removeEdgeM(g, v1, v2);
				continue;
			}

			// IT = imprimir transposto
			if (cmd1 == 'I' && cmd2 == 'T'){
				cmd1 = fgetc(stdin); // limpar buffer
				if (dig == 'D') transposeGraphM(g);
				continue;
			}

			// MP = menor peso
			if (cmd1 == 'M' && cmd2 == 'P'){
				cmd1 = fgetc(stdin); // limpar buffer
				getLowerM(g);
				continue;
			} 
		}
	}

	// desalocando grafo
	destroyGraphM(g);
}

void runListGraph(char dig){
	int vertexNum, edgeNum;
	int v1, v2, value;
	int i;
	char cmd1, cmd2;

	// ler numero de vertices e arestas
	scanf("%d %d\n", &vertexNum, &edgeNum);

	// criar grafo
	LGraph *g = createGraphL(vertexNum, dig == 'D' ? true : false);

	// ler arestas e inserir no grafo
	for (i = 0; i < edgeNum; i++){
		scanf("%d %d %d\n", &v1, &v2, &value);
		insertEdgeL(g, v1, v2, value);
	}

	// ler comandos
	while(!feof(stdin)){
		cmd1 = fgetc(stdin);
		if (!feof(stdin)){
			cmd2 = fgetc(stdin);

			// decodificar comando
			// IG = imprimir grafo
			if (cmd1 == 'I' && cmd2 == 'G'){
				cmd1 = fgetc(stdin); // limpar buffer
				printGraphL(g);
				continue;
			} 

			// VA = vertices adjacentes
			if (cmd1 == 'V' && cmd2 == 'A'){
				cmd1 = fgetc(stdin); // limpar buffer
				scanf("%d\n", &v1);
				getAdjacencyL(g, v1);
				continue;
			} 

			// AA = adicionar arestas
			if (cmd1 == 'A' && cmd2 == 'A'){
				scanf("%d %d %d\n", &v1, &v2, &value);
				insertEdgeL(g, v1, v2, value);
				continue;
			}

			// RA = remover arestas
			if (cmd1 == 'R' && cmd2 == 'A'){
				scanf("%d %d\n", &v1, &v2);
				removeEdgeL(g, v1, v2);
				continue;
			}

			// IT = imprimir transposto
			if (cmd1 == 'I' && cmd2 == 'T'){
				cmd1 = fgetc(stdin); // limpar buffer
				if (dig == 'D') transposeGraphL(g);
				continue;
			}

			// MP = menor peso
			if (cmd1 == 'M' && cmd2 == 'P'){
				cmd1 = fgetc(stdin); // limpar buffer
				getLowerL(g);
				continue;
			} 
		}
	}

	// desalocando grafo
	destroyGraphL(g);
}


int main (int argc, char *argv[]){

	char graphType, digraph;
	scanf("%c %c", &digraph, &graphType);
	fgetc(stdin);

	// escolhe de acordo com o tipo de grafo implementado
	switch (graphType){
		case 'M':
			runMatrixGraph(digraph);
			break;
		case 'L':
			runListGraph(digraph);
			break;
	}

	return 0;
}