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
	//���l1Ϊ�գ�����l2
	if (l2 == NULL)
		return l1;
	//���l2Ϊ�գ�����l1
	struct ListNode* head = NULL, *tail = NULL;
	//head��ʾ����ͷ�ڵ㣬tail��ʾ����β�ڵ㣬����β��

	//˭С˭��ͷ�ڵ�
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
	{//ȡС��β��
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
	//��һ������Ϊ�գ���һ������ֵ
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