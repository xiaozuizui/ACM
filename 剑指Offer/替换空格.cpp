#include "stdafx.h"
#include <string>
#include "�滻�ո�.h"
using namespace std;
/**
 * LRU �з�����Ҫ�滻
 * 
 */
string ReplaceBlank(string s)
{
	return {};
}

char* ReplaceBlank(char s[],char replacechar)
{
	//�滻Ϊ%@#

	char * p = s;
	int need = 0;

	while (*p++ != '\0')
		if (*p == replacechar)
			need++;
	
	char *end = p+2*need;
	*end  = '\0';

	while(p!=s)
	{
		if (*p == replacechar)
		{
			*end-- = '#';
			*end-- = '@';
			*end= '%';
		}
		else
			*end = *p;

		end--;
		p--;
	}
	return nullptr;
}

