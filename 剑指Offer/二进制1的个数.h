#pragma once


//��Ҫѭ��intλ������
int NumberOf1_1(int n)
{
	int flag = 1;
	int count = 0;
	while(flag)
	{
		if (flag&n)
			count++;
		flag <<= 1;
	}
	return count;
}

//�ڶ��ֽⷨ���������е�1���0
//

int NumberOf1_2