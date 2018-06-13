// 首查法逆置单链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* ReversList(ListNode* l)
{

	ListNode* head = new ListNode(0);

	ListNode* ne = l->next;
	ListNode* temp = ne;

	head->next = l;
	l->next = NULL;

	while (ne != NULL)
	{
		temp = ne;
		ne = ne->next;
		temp->next = head->next;
		head->next = temp;
	}


	//l = head->next;
	return head->next;


}

int main()
{
	ListNode* l = new ListNode(0);
	l->next = new ListNode(0);
	ListNode* temp = l->next;
	for(int i=1;i<3;i++)
	{
		temp->val = i;
		temp->next = new ListNode(0);
		temp = temp->next;

	}

	 l = ReversList(l);
    return 0;
}

