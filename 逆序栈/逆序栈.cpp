// 逆序栈.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include "../ACM/mathtool.h"

void InverseStack();
int GetAndRemoveLast();
std::stack<int> stack_;

int main()
{
	//int temp;
	int n;
	std::cin >> n;

	for(int i=0;i<n;i++)
	{
		int temp;
		std::cin >> temp;
		stack_.push(temp);
	}
	ShowStack<int>(stack_);
	//GetAndRemoveLast();
	InverseStack();
	ShowStack<int>(stack_);
    return 0;
}


int GetAndRemoveLast()
{
	const int temp = stack_.top();
	stack_.pop();

	if (stack_.empty())
		return temp;
	else
	{
		int last = GetAndRemoveLast();
		stack_.push(temp);
		return last;
	}
}

void InverseStack()
{
	if (stack_.empty())
		return;
	int last = GetAndRemoveLast();
	
	InverseStack();
	stack_.push(last);
}
