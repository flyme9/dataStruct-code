#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast = head, *slow = head;
	//fast每次跳两步，slow每次跳一次
	while ((fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
int main()
{
	return 0;
}