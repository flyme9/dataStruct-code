#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	//如果l1为空，返回l2
	if (l2 == NULL)
		return l1;
	//如果l2为空，返回l1
	struct ListNode* head = NULL, *tail = NULL;
	//head表示链表头节点，tail表示链表尾节点，方便尾插

	//谁小谁做头节点
	if (l1->val < l2->val)
	{
		head = tail = l1;
		l1 = l1->next;
	}
	else
	{
		head = tail = l2;
		l2 = l2->next;
	}
	while (l1&&l2)
	{//取小的尾插
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	//有一个链表为空，另一个还有值
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;
	return head;
}
int main()
{
	return 0;
}