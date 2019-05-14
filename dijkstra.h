#pragma once
#include "graph.h"
#include <queue>

typedef pair<double, int>path;//(单源最短路长度, 目的顶点编号)
vector<double> dijkstra(graph G, int s)//s为源
{
	vector <double>dist(G.size(), INF_EDGEWEIGHT);
	if (s >= G.size())
		return dist;

	struct greator {
		int operator() (const path&a, const path&b)
		{
			return a.first > b.first;
		}
	};
	priority_queue<path, vector<path>, greator> Q;

	path p;
	int vert;
	dist[s] = 0;
	Q.push(path(0, s));
	while (!Q.empty())
	{
		p = Q.top(), Q.pop();
		vert = p.second;//用v来relax
		if (p.first > dist[vert])continue;//说明这是用直接插入来代替decrease_key时产生的多余的元素，直接跳过
		for (auto iter = G.adjList[vert].begin(); iter != G.adjList[vert].end(); iter++)
		{
			auto e = *iter;
			if (dist[vert] + e.weight < dist[e.to])
			{
				dist[e.to] = dist[vert] + e.weight;
				Q.push(path(dist[e.to], e.to));
			}
		}
	}
	return dist;
}

vector<double> dijkstra(graph G, int s, vector<int> &pre)//s为源
{
	vector <double>dist(G.size(), INF_EDGEWEIGHT);
	pre = vector<int>(G.size(), UNREACH_PATH);
	if (s >= G.size())
		return dist;

	struct greator {
		int operator() (const path&a, const path&b)
		{
			return a.first > b.first;
		}
	};
	priority_queue<path, vector<path>, greator> Q;

	path p;
	int vert;
	dist[s] = 0;
	pre[s] = END_PATH;
	Q.push(path(0, s));
	while (!Q.empty())
	{
		p = Q.top(), Q.pop();
		vert = p.second;//用v来relax
		if (p.first > dist[vert])continue;//说明这是用直接插入来代替decrease_key时产生的多余的元素，直接跳过
		for (auto iter = G.adjList[vert].begin(); iter != G.adjList[vert].end(); iter++)
		{
			auto e = *iter;
			if (dist[vert] + e.weight < dist[e.to])
			{
				pre[e.to] = vert;//更新e.to的前驱
				dist[e.to] = dist[vert] + e.weight;
				Q.push(path(dist[e.to], e.to));
			}
		}
	}
	return dist;
}