#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include "utils.h"

typedef struct MGraph MGraph;

MGraph *createGraphM(int n, bool digraph);
int insertEdgeM(MGraph *g, int v1, int v2, int value);
int removeEdgeM(MGraph *g, int v1, int v2);
void printGraphM(MGraph *g);
void transposeGraphM(MGraph *g);
void getAdjacencyM(MGraph *g, int v);
void getLowerM(MGraph *g);
void destroyGraphM(MGraph *g);

#endif