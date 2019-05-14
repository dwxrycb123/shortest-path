#include "graph.h"
#include "dijkstra.h"
#include "bellmanFord.h"
#include "floydWarshall.h"
#include "johnson.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	//测试dijkstra算法
	graph G(5);
	G.addEdge(10, 0, 1);
	G.addEdge(1, 1, 2);
	G.addEdge(2, 1, 4);
	G.addEdge(3, 4, 1);
	G.addEdge(9, 4, 2);
	G.addEdge(4, 2, 3);
	G.addEdge(6, 3, 2);
	G.addEdge(7, 3, 0);
	G.addEdge(5, 0, 4);
	G.addEdge(2, 4, 3);
	vector<double>dist;
	vector<int>pre;
	dist = dijkstra(G, 0, pre);
	cout << "Dijkstra:" << endl;
	for (auto iter = dist.begin(); iter != dist.end(); iter++)
	{
		cout << (*iter) << " ";
	}
	cout << endl;
	for (auto iter = pre.begin(); iter != pre.end(); iter++)
	{
		cout << (*iter) << " ";
	}
	cout << endl;
	//dijkstra 示例输出结果正确


	G = graph(5);
	G.addEdge(6, 0, 1);
	G.addEdge(5, 1, 2);
	G.addEdge(-2, 2, 1);
	G.addEdge(8, 1, 4);
	G.addEdge(7, 3, 2);
	G.addEdge(-3, 4, 2);
	G.addEdge(-4, 1, 3);
	G.addEdge(2, 3, 0);
	G.addEdge(7, 0, 4);
	G.addEdge(9, 4, 3);
	bellmanFord(G, 0, dist, pre);
	cout << "BellmanFord:" << endl;
	for (auto iter = dist.begin(); iter != dist.end(); iter++)
	{
		cout << (*iter) << " ";
	}
	cout << endl;
	for (auto iter = pre.begin(); iter != pre.end(); iter++)
	{
		cout << (*iter) << " ";
	}
	cout << endl;
	//bellmanFord 示例输出结果正确

	G = graph(5);
	G.addEdge(3, 0, 1);
	G.addEdge(8, 0, 2);
	G.addEdge(-4, 0, 4);
	G.addEdge(1, 1, 3);
	G.addEdge(7, 1, 4);
	G.addEdge(4, 2, 1);
	G.addEdge(2, 3, 0);
	G.addEdge(-5, 3, 2);
	G.addEdge(6, 4, 3);
	vector<vector<int> >pre_allPair;
	auto matrix = floydWarshall(G, pre_allPair);
	cout << "floyd:" << endl;
	for (int i = 0; i < G.size(); i++)
	{
		for (int j = 0; j < G.size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << "pre:" << endl;
	for (int i = 0; i < G.size(); i++)
	{
		for (int j = 0; j < G.size(); j++)
			cout << pre_allPair[i][j] << " ";
		cout << endl;
	}

	johnson(G, matrix, pre_allPair);
	cout << "johnson:" << endl;
	for (int i = 0; i < G.size(); i++)
	{
		for (int j = 0; j < G.size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << "pre:" << endl;
	for (int i = 0; i < G.size(); i++)
	{
		for (int j = 0; j < G.size(); j++)
			cout << pre_allPair[i][j] << " ";
		cout << endl;
	}




	system("pause");
	return 0;
}