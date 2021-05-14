#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode 
{
	int val;
	struct ListNode *next;
}ListNode;
struct ListNode* partition(struct ListNode* head, int x)
{
	//创建两个带头链表，尾指针方便进行尾插
	struct ListNode* lessHead, *lessTail;
	struct ListNode* greaterHead, *greaterTail;
	//开辟头节点和尾指针空间
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//初始化
	lessHead->next = greaterHead->next = NULL;
	//判断分割
	struct ListNode* cur = head;
	while (cur)
	{
		if (cur->val < x)
		{//如果小于x，将cur放到值小的链表
			lessTail->next = cur;
			lessTail = lessTail->next;
		}
		else
		{//如果大于等于x，将cur放到值小的链表
			greaterTail->next = cur;
			greaterTail = greaterTail->next;
		}
		cur = cur->next;
		greaterTail->next = NULL;
	}
	//将小值的链表链接大值的链表
	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;
	struct ListNode* list = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return list;
}
int main()
{
	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* n6 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* n7 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 3;
	n1->next = n2;
	n2->val = 5;
	n2->next = n3;
	n3->val = 8;
	n3->next = n4;
	n4->val = 5;
	n4->next = n5;
	n5->val = 10;
	n5->next = n6;
	n6->val = 2;
	n6->next = n7;
	n7->val = 1;
	n7->next = NULL;
	n1 = partition(n1, 5);
	while (n1)
	{
		printf("%d->", n1->val);
		n1 = n1->next;
	}
	printf("NULL\n");
	return 0;
}