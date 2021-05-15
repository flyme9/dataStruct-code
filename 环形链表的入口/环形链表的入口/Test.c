#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast = head, *slow = head;
	while (fast&&fast->next)
	{
		slow = slow->next;//慢指针走一步
		fast = fast->next->next;//快指针走两步
								//推到结论：一个指针从相遇点开始走，一个从链表头走
		if (fast == slow)
		{//快指针和慢指针相遇
			struct ListNode* meet = slow;
			while (head != meet)
			{
				head = head->next;
				meet = meet->next;
			}
			return meet;
		}
	}
	return NULL;
}
int main()
{
	return 0;
}