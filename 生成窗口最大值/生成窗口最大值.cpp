// 生成窗口最大值.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <deque>
#include <iostream>

//p19
//使用o（n）量级算法

//使用双端队列，队列对头为最大值

int n;//数组大小
int w;//窗口宽度
int arr[100];
int res[100];


void GetMaxWindows()
{
	std::deque<int> que;
	int z = 0;
	for(int i=0;i<n;i++)//扫描元素
	{
		if (que.empty())
			que.push_front(i);
		else
		{
			if (arr[que.back()] > arr[i])//保持对头最大
				que.push_back(i);
			else
			{
				while (!que.empty() && arr[que.back()] <= arr[i])
					que.pop_back();
				que.push_back(i);
			}

			if(i>=w)
			{
				while (que.front() < i-3)//检查标记是否过期
					que.pop_front();


				res[z++] = arr[que.front()];
			}
			
		}
	}
}

int main()
{
	std::cin >> n >> w;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	GetMaxWindows();

	for (int i = 0; i < n - w; i++)
		std::cout << res[i];
    return 0;
}

