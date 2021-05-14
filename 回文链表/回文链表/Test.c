#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* newHead = NULL, *cur = head;
	while (cur)
	{
		struct ListNode* next = cur->next;
		//头插
		cur->next = newHead;
		newHead = cur;
		cur = next;
	}
	return newHead;
}
bool isPalindrome(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return true;
	//找到链表的中间节点
	struct ListNode* fast = head, *slow = head, *prev = NULL;
	while (fast && fast->next)
	{
		prev = slow;//断开slow和head
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = NULL;
	slow = reverseList(slow);
	while (head)
	{
		if (head->val != slow->val)
		{
			return false;
		}
		else
		{
			head = head->next;
			slow = slow->next;
		}
	}
	return true;
}
int main()
{
	return 0;
}