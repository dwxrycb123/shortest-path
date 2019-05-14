#pragma once
#include<iostream>
#include<vector>
#define INF_EDGEWEIGHT 10000000
#define UNREACH_PATH -2
#define END_PATH -1
using namespace std;

struct edge
{
	edge(double w, int t);//weight, to
	double weight;//weight
	int to;//所指顶点编号

};

class graph
{
private:
	int vertNum = 0;
	vector<vector<edge> > adjList;
public:
	graph(int vnum = 0);//vertex_number 
	bool addEdge(double w, int f, int t);//weight, from, to
	void addVertex();
	int size();
	friend vector<double> dijkstra(graph G, int s);
	friend vector<double> dijkstra(graph G, int s, vector<int> &pre);//pre[i]返回最短路径树中顶点i的前驱
	friend bool bellmanFord(graph G, int s, vector<double>& dist);
	friend bool bellmanFord(graph G, int s, vector<double>& dist, vector<int> &pre);//pre[i]返回最短路径树中顶点i的前驱
	friend vector<vector<double> > floydWarshall(graph G);
	friend vector<vector<double> > floydWarshall(graph G, vector<vector<int> > &pre);//pre[i][j]返回i->j最短路径中倒数第二个顶点
	friend bool johnson(graph G, vector<vector<double> >&dist);
	friend bool johnson(graph G, vector<vector<double> >&dist, vector<vector<int> > &pre);//pre[i][j]返回i->j最短路径中倒数第二个顶点

};