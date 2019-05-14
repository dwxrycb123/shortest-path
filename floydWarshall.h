#pragma once
#include "graph.h"
vector<vector<double> > floydWarshall(graph G) 
{
	vector<vector<double> >dist(G.size(), vector<double>(G.size(), INF_EDGEWEIGHT));
	for (int v = 0; v < G.size(); v++) 
	{
		dist[v][v] = 0;
		for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
		{
			auto e = *iter;
			dist[v][e.to] = e.weight;
		}
	}
	for (int k = 0; k < G.size(); k++)
		for (int i = 0; i < G.size(); i++)
			for (int j = 0; j < G.size(); j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	return dist;
}
vector<vector<double> > floydWarshall(graph G, vector<vector<int> > &pre)
{
	vector<vector<double> >dist(G.size(), vector<double>(G.size(), INF_EDGEWEIGHT));
	pre = vector<vector<int> >(G.size(), vector<int>(G.size(), UNREACH_PATH));
	for (int v = 0; v < G.size(); v++)
	{
		dist[v][v] = 0;
		pre[v][v] = END_PATH;
		for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
		{
			auto e = *iter;
			dist[v][e.to] = e.weight;
			pre[v][e.to] = v;
		}
	}
	for (int k = 0; k < G.size(); k++)
		for (int i = 0; i < G.size(); i++)
			for (int j = 0; j < G.size(); j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					pre[i][j] = pre[k][j];
				}
	return dist;
}