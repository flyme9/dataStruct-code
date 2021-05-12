#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};
//��ָ�뷴ת����
struct ListNode* reverseList(struct ListNode* head) {
	//����Ϊ�ջ�ֻ��һ���ڵ�����
	if (head == NULL || head->next == NULL)
		return head;
	//������һ�����Ͻڵ�
	struct ListNode* node1 = NULL, *node2 = head, *node3 = head->next;
	//node1ָ��գ�node2����ָ��node1��Ľڵ㣬node3���ڱ���node2��Ľڵ�
	while (node2 != NULL)
	{   //��ת����
		node2->next = node1;
		//��������ת����ָ����һ���ڵ�
		node1 = node2;
		node2 = node3;
		//��node�ߵ�NULLʱ��node3���ڵ���
		if (node3 == NULL)
			node3 = node3->next;
	}
	return node1;
}

//ͷ�巨
struct ListNode* reverseList_2(struct ListNode* head)
{
	if (head == NULL)
		return head;
	struct ListNode* cur = head, *next = head->next, *newhead = NULL;
	while (cur)
	{
		cur->next = newhead;

		newhead = cur;
		cur = next;
		if (next != NULL)
			next = next->next;
	}
	return newhead;
}
int main()
{
	return 0;
}