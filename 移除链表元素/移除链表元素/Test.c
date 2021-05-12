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
			{//ͷ�ڵ����val�����
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{//ͷ�ڵ㲻��val�����
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