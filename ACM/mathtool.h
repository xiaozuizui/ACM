#pragma once

#include"stdafx.h"
#include "stack"
#include <iostream>

const int MAXN = 1010;
const int MAXM = 1010;

//template <class T>
class Matrix {
public:
	int n, m;
	int a[1010][1010];
	Matrix(){}

	//Matrix(int N, int M);
	
	void clear() { n = m = 0; memset(a, 0, sizeof(a)); }

	/*Matrix operator -(const Matrix &b) const {
		Matrix tmp;
		tmp.n = n;
		tmp.m = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp.a[i][j] = a[i][j] - b.a[i][j];
		return tmp;
	}
	Matrix operator +(const Matrix &b) const {
		Matrix tmp;
		tmp.n = n;
		tmp.m = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp.a[i][j] = a[i][j] + b.a[i][j];
		return tmp;
	}
	Matrix operator *(const Matrix &b)const {
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < b.m; j++)
				for (int k = 0; k < m; k++)
					tmp.a[i][j] += a[i][k] * b.a[k][j];
		return tmp;
	}
	*/
	//void Inverse();
};



/*
Gauss 消元
a:方程组矩阵
n:未知数个数
l,ans:储存解 ，l[]表示是否为自由元
*/
inline int Gauss(double a[][MAXN], bool l[], double ans[]);

template <typename T>
void ShowStack(std::stack<T> stack)
{
	while(!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
	

}

