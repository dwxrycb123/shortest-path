#pragma once
#include "graph.h"

bool bellmanFord(graph G, int s, vector<double>& dist)
{
	dist = vector<double>(G.size(), INF_EDGEWEIGHT);
	dist[s] = 0;
	if (s >= G.size())
		return false;
	for (int i = 0; i < G.size() - 1; i++)
		for (int v = 0; v < G.size(); v++)
			for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
			{
				auto e = *iter;
				if (dist[e.to] > dist[v] + e.weight) 
					dist[e.to] = dist[v] + e.weight;
			}
	for (int v = 0; v < G.size(); v++)
		for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
		{
			auto e = *iter;
			if (dist[e.to] > dist[v] + e.weight)
				return false;
		}
	return true;
}
bool bellmanFord(graph G, int s, vector<double>& dist, vector<int> &pre)
{
	dist = vector<double>(G.size(), INF_EDGEWEIGHT);
	pre = vector<int>(G.size(), UNREACH_PATH);
	dist[s] = 0;
	pre[s] = END_PATH;
	if (s >= G.size())
		return false;
	for (int i = 0; i < G.size() - 1; i++)
		for (int v = 0; v < G.size(); v++)
			for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
			{
				auto e = *iter;
				if (dist[e.to] > dist[v] + e.weight) {
					dist[e.to] = dist[v] + e.weight;
					pre[e.to] = v;
				}
			}
	for (int v = 0; v < G.size(); v++)
		for (auto iter = G.adjList[v].begin(); iter != G.adjList[v].end(); iter++)
		{
			auto e = *iter;
			if (dist[e.to] > dist[v] + e.weight)
				return false;
		}
	return true;
}