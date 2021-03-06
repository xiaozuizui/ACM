// 构造数组的MaxTree.cpp: 定义控制台应用程序的入口点。
//


//MaxTree 给定一个没有重复元素的数组A，
//定义A上的MaxTree如下：MaxTree的根节点为A中最大的数，根节点的左子树为数组中最大数左边部分的MaxTree，
//右子树为数组中最大数右边部分的MaxTree。请根据给定的数组A，设计一个算法构造这个数组的MaxTree。

//如果能够确定每个节点的父亲节点，则可以构造出整棵树。
//找出每个数往左数第一个比他大的数和往右数第一个比他大的数，两者中较小的数即为该数的父亲节点。
//如：[3, 1, 2]，3没有父亲节点，1的父亲节点为2，2的父亲节为3。
//并且可以根据与父亲的位置关系来确定是左儿子还是右儿子。接下来的问题是如何快速找出每个数往左、往右第一个比他大的数。这里需要用到数据结构栈。
//以找每个数左边第一个比他大的数为例，从左到右遍历每个数，栈中保持递减序列，新来的数不停的Pop出栈顶直到栈顶比新数大或没有数。
//以[3, 1, 2]为例，首先3入栈，接下来1比3小，无需pop出3，1入栈，并且确定了1往左第一个比他大的数为3。接下来2比1大，1出栈，2比3小，2入栈。并且确定了2往左第一个比他大的数为3。
//用同样的方法可以求得每个数往右第一个比他大的数。时间复杂度O(n)，空间复杂度也是O(n)为最优解法。


#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int value;
	Node* left;
	Node* right;
}MaxTreeNode;

typedef MaxTreeNode MaxTree;

int n;
int arr[100];
MaxTreeNode nodes[100];

MaxTree Tree;

void GetMaxTree();

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		nodes[i].value = arr[i];
		nodes[i].left = NULL;
		nodes[i].right = NULL;

	}
	GetMaxTree();

    return 0;
}

void GetMaxTree()
{
	for(int i=0;i<n;i++)
	{
		int left = 0;
		int right = 0;

		int left_index=-1;
		int right_index=-1;

		int father;

		//找到左边第一个比它大的节点
		for(int j=i-1;j>=0;j--)
		{
			if(nodes[j].value>nodes[i].value)
			{
				left = nodes[j].value;
				left_index = j;
				break;;
			}
		}
		//
		for(int j=i+1;j<n;j++)
		{
			if(nodes[j].value>nodes[i].value)
			{
				right = nodes[j].value;
				right_index = j;
				break;
			}
		}

		if(left_index==-1&&right_index==-1)
			continue;

		else if(left_index==-1)
		{
			father = right_index;
		}
		else if(right_index == -1)
		{
			father = left_index;
		}
		else
		{
			if (left < right)
				father = left_index;
			else
				father = right_index;
		}
		

		if (nodes[father].left == NULL)
			nodes[father].left = &nodes[i];
		else
			nodes[father].right = &nodes[i];
	}
}

