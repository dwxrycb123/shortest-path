#include "graph.h"


edge::edge(double w, int t) {
	weight = w;
	to = t;
}
graph::graph(int vnum)
{
	vertNum = vnum;
	adjList.resize(vnum);
}
bool graph::addEdge(double w, int f, int to)
{
	if (f >= vertNum || to >= vertNum)
		return false;
	adjList[f].push_back(edge(w, to));
	return true;
}
void graph::addVertex() 
{
	vertNum++;
	adjList.resize(vertNum + 1);
}
int graph::size()
{
	return vertNum;
}