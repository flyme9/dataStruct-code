#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* prev = NULL, *cur = head;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			if (cur == head)
			{//头节点就是val的情况
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{//头节点不是val的情况
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
int main()
{
	return 0;
}