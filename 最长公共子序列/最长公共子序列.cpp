// 最长公共子序列.cpp: 定义控制台应用程序的入口点。
//


//dp[i][j]  表示s1-si 与t1-tj的最长公共子序列
//注意公共子序列并不是连续的
//连续匹配可用KMP

#include "stdafx.h"
#include <iostream>

int n, m;
char s[100];
char t[100];

int dp[100][100];
int main()
{
	memset(dp, 0, sizeof(int) * 100 * 100);

	std::cin >> n, m;
	for (int i = 0; i < n; i++)
		std::cin >> s[i];
	for (int j = 0; j < m; j++)
		std::cin >> t[j];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(s[i]==t[j])
				dp[i][j]=
		}
	dp[0][0] = s[0] == t[0];
    return 0;
}

