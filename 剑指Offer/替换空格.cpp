#include "stdafx.h"
#include <string>
#include "Ìæ»»¿Õ¸ñ.h"
using namespace std;
/**
 * LRU ÖÐ·ûºÅÐèÒªÌæ»»
 * 
 */
string ReplaceBlank(string s)
{
	return {};
}

char* ReplaceBlank(char s[],char replacechar)
{
	//Ìæ»»Îª%@#

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

