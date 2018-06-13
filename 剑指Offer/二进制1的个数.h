#pragma once


//需要循环int位数次数
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

//第二种解法，把数当中的1变成0
//

int NumberOf1_2