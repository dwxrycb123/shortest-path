#pragma once
#include "graph.h"
#include "bellmanFord.h"
#include "dijkstra.h"
bool johnson(graph G, vector<vector<double> > &ret)
{
	ret = vector<vector<double> >();
	vector<double>h;
	G.addVertex();
	int s = G.size() - 1;
	for (int v = 0; v < s; v++)
		G.addEdge(0, s, v);
	if (!bellmanFord(G, s, h))
		return false;

	//reweight
	for (int v = 0; v < s; v++)
		for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
			(*iter).weight += (h[v] - h[(*iter).to]);

	for (int v = 0; v < s; v++)
	{
		auto dist = dijkstra(G, v);
		dist.resize(s);
		for (int u = 0; u < s; u++) 
			dist[u] += h[u] - h[v];
		ret.push_back(dist);
	}
	return true;
}

bool johnson(graph G, vector<vector<double> > &ret, vector<vector<int> > &pre)
{
	ret = vector<vector<double> >();
	pre = vector<vector<int> >();
	vector<int> pre_tmp;
	vector<double>h;
	G.addVertex();
	int s = G.size() - 1;
	for (int v = 0; v < s; v++)
		G.addEdge(0, s, v);
	if (!bellmanFord(G, s, h))
		return false;

	//reweight
	for (int v = 0; v < s; v++)
		for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
			(*iter).weight += (h[v] - h[(*iter).to]);

	for (int v = 0; v < s; v++)
	{
		auto dist = dijkstra(G, v, pre_tmp);
		dist.resize(s);
		pre_tmp.resize(s);
		pre.push_back(pre_tmp);
		for (int u = 0; u < s; u++)
			dist[u] += h[u] - h[v];
		ret.push_back(dist);
	}
	return true;
}