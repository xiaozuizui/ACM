// 图着色问题.cpp: 定义控制台应用程序的入口点。
//二分图判定

#include "stdafx.h"
#include <vector>
#include <iostream>

std::vector<int> G[10];
int vn;//顶点数
int en;//边数
int color[10];

bool dfs(int v, int c);

int main()
{
	memset(color, 0, sizeof(int) * 10);
	std::cin >> vn>>en;
	for(int i=0;i<en;i++)
	{
		int s, t;
		std::cin >> s >> t;
		G[s].push_back(t);
		G[t].push_back(s);//无向图
	}

	std::cout<<dfs(0, 1);//默认为连通图
    return 0;
}

bool dfs(int v,int c)//color
{
	color[v] = c;
	for(int i=0;i<G[v].size();i++)
	{
		if (color[G[v][i]] == c) return false;
		if (color[G[v][i]] == 0)
			if (!dfs(G[v][i], -c))
				return false;

	}
	return true;

}