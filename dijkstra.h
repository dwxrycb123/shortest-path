#pragma once
#include "graph.h"
#include <queue>

typedef pair<double, int>path;//(��Դ���·����, Ŀ�Ķ�����)
vector<double> dijkstra(graph G, int s)//sΪԴ
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
		vert = p.second;//��v��relax
		if (p.first > dist[vert])continue;//˵��������ֱ�Ӳ���������decrease_keyʱ�����Ķ����Ԫ�أ�ֱ������
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

vector<double> dijkstra(graph G, int s, vector<int> &pre)//sΪԴ
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
		vert = p.second;//��v��relax
		if (p.first > dist[vert])continue;//˵��������ֱ�Ӳ���������decrease_keyʱ�����Ķ����Ԫ�أ�ֱ������
		for (auto iter = G.adjList[vert].begin(); iter != G.adjList[vert].end(); iter++)
		{
			auto e = *iter;
			if (dist[vert] + e.weight < dist[e.to])
			{
				pre[e.to] = vert;//����e.to��ǰ��
				dist[e.to] = dist[vert] + e.weight;
				Q.push(path(dist[e.to], e.to));
			}
		}
	}
	return dist;
}