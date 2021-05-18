#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int val;
	struct Node *next;
	struct Node *random;
};
struct Node* copyRandomList(struct Node* head)
{
	//1.拷贝节点，每个拷贝节点链接到老的节点后面，
	//2.处理拷贝节点的ranmon，老节点radmon的下一个节点就是拷贝节点的radmon要指向的节点
	//3.拆解链表
	if (head == NULL)
		return NULL;
	//1.拷贝
	struct Node* cur = head;
	while (cur)
	{
		//开辟拷贝节点，并将原链表val给拷贝节点
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->next = NULL;
		copy->random = NULL;
		copy->val = cur->val;

		//保存老节点的下一个节点
		struct Node* next = cur->next;
		//链接拷贝节点在原节点之后
		copy->next = next;
		cur->next = copy;
		cur = next;//迭代
	}
	//2.处理radmon
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;//指向拷贝节点
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		cur = cur->next -> next;//指向下一个老节点
	}
	//3.拆解
	cur = head;
	struct Node* copyHead = head->next;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;

		cur->next = next;
		if (next)
			copy->next = next->next;
		else
			copy->next = NULL;
		cur = next;
	}
	return copyHead;
}
int main()
{
	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n5 = (struct Node*)malloc(sizeof(struct Node));
	n1->val = 7;
	n1->next = n2;
	n1->random = NULL;
	n2->val = 13;
	n2->next = n3;
	n2->random = n1;
	n3->val = 11;
	n3->next = n4;
	n3->random = n5;
	n4->val = 10;
	n4->next = n5;
	n4->random = n3;
	n5->val = 1;
	n5->next = NULL;
	n5->random = n1;
	struct Node* cur = copyRandomList(n1);
	struct Node* copy = cur;
	while (copy != NULL)
	{
		static int i = 1;
		printf("n%d:random->%p       ", i, copy->random);
		printf("n%d:next  ->%p       ", i, copy);
		printf("\n");
		i++;
		copy = copy->next;
	}
	return 0;
}