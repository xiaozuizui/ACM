// 最短路径Bellman-Ford.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define INF 99999
struct edge { int from; int to; int cost; };
edge es[100];//边表
int d[100];//最短路
int V, E;//顶点数，边数

bool DAG;
void Short_path(int s);//从s点出发的最短路

int main()
{
	int s;
	std::cin >> DAG;//是否为有向图
	std::cin >> V >> E;
	if (!DAG)
		E = 2 * E;

	for(int i=0;i<E;i++)
	{
		std::cin >> es[i].from >> es[i].to >> es[i].cost;
		if (!DAG)
		{
			es[i +1].to = es[i].from;
			es[i +1].from = es[i].to;
			es[i +1].cost = es[i].cost;
			i++;
		}
		

	}

	for (int i = 0; i < V; i++)
		d[i] = INF;
	std::cin >> s;
	Short_path(s);
	
    return 0;
}

void Short_path(int s)
{
	d[s] = 0;

	while (true)
	{
		bool update = false;
		for (int i = 0; i < E; i++)
		{
			edge tempe = es[i];

			if (d[tempe.from] != INF && d[tempe.to] > d[tempe.from] + tempe.cost)//s点可达tempe.from 且满足条件
			{
				d[tempe.to] = d[tempe.from] + tempe.cost;
				update = true;
			}

			//遍历完一次没有发生更新 说明找到最短路

		}

		if (!update) break;
	}
}


