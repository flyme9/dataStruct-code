#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};
//三指针反转方法
struct ListNode* reverseList(struct ListNode* head) {
	//链表为空或只有一个节点的情况
	if (head == NULL || head->next == NULL)
		return head;
	//链表有一个以上节点
	struct ListNode* node1 = NULL, *node2 = head, *node3 = head->next;
	//node1指向空，node2用于指向node1后的节点，node3用于保存node2后的节点
	while (node2 != NULL)
	{   //反转链表
		node2->next = node1;
		//迭代，反转结束指向下一个节点
		node1 = node2;
		node2 = node3;
		//当node走到NULL时，node3不在迭代
		if (node3 == NULL)
			node3 = node3->next;
	}
	return node1;
}

//头插法
struct ListNode* reverseList_2(struct ListNode* head)
{
	if (head == NULL)
		return head;
	struct ListNode* cur = head, *next = head->next, *newhead = NULL;
	while (cur)
	{
		cur->next = newhead;

		newhead = cur;
		cur = next;
		if (next != NULL)
			next = next->next;
	}
	return newhead;
}
int main()
{
	return 0;
}