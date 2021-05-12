#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* FindKthToTail(struct ListNode* pHead, int k) 
{
	struct ListNode* fast = pHead, *slow = pHead;
	while (k--)
	{
		if (fast)
			fast = fast->next;
		else
			return NULL;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
int main()
{
	return 0;
}