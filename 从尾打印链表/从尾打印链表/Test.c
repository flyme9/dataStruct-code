#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* reverseList_2(struct ListNode* head,int* size)
{
	if (head == NULL)
		return head;
	struct ListNode* cur = head, *next = head->next, *newhead = NULL;
	while (cur)
	{
		(*size)++;
		cur->next = newhead;

		newhead = cur;
		cur = next;
		if (next != NULL)
			next = next->next;
	}
	return newhead;
}
int* reversePrint(struct ListNode* head, int* returnSize) {
	int size = 0;
	//ÄæÖÃÁ´±í
	struct ListNode* reveList = reverseList_2(head, &size);
	if (reveList == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	int i = 0;
	int* arr = (int*)malloc(sizeof(int)*size+1);
	while (reveList)
	{
		arr[i] = reveList->val;
		reveList = reveList->next;
		i++;
	}
	*returnSize = i;
	return arr;
}
int main()
{
	int size = 0;
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	int* arr = reversePrint(n1, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}