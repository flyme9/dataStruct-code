#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	unsigned int data = 0;//两数相加
	unsigned int cnt = 0;//判断是否为空链表
	unsigned int flag = 0;//进位

	struct ListNode* newlist = NULL;//存加完之后的值
	struct ListNode* listHead = NULL;//指向链表头节点
	struct ListNode* listTemp = NULL;//指向链表尾节点

	if ((l1 != NULL) && (l2 != NULL))
	{
		do
		{
			data = flag;
			if (l1 != NULL)
			{
				data = data + l1->val;//链表1和data与falg相加
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				data = data + l2->val;//和链表1相加后，data是链表1+进位的值，在和链表2相加
				l2 = l2->next;
			}
			flag = data / 10;//判断进位
			newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newlist != NULL)
			{
				newlist->next = NULL;
				newlist->val = data % 10;//存放值
				if (cnt == 0)
				{//如果链表为空
					listHead = newlist;
					listTemp = listHead;
				}
				else
				{//有一个以上节点
					listTemp->next = newlist;//指向值的地址
					listTemp = listTemp->next;//指向新尾节点
				}
			}
			cnt++;
		} while ((l1 != NULL) || (l2 != NULL));
		if (flag == 1)
		{//如果结束后有进位，开辟一个空间
			cnt++;
			newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newlist != NULL)
			{
				newlist->next = NULL;
				newlist->val = 1;//存放进位值
				listTemp->next = newlist;//指向新尾节点
			}
		}
	}
	return listHead;
}
int main()
{
	struct ListNode* s1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	s1->val = 2;
	s1->next = s2;
	s2->val = 4;
	s2->next = s3;
	s3->val = 3;
	s3->next = NULL;
	l1->val = 5;
	l1->next = l2;
	l2->val = 6;
	l2->next = l3;
	l3->val = 6;
	l3->next = NULL;
	struct ListNode* node = addTwoNumbers(s1, l1);
	while (node)
	{
		printf("%d->", node->val);
		node = node->next;
	}
	printf("NULL\n");
	return 0;
}