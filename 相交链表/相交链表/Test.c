#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* curA = headA;
	int lenA = 0;
	while (curA)
	{//计算出链表A的长度
		lenA++;
		curA = curA->next;
	}

	struct ListNode* curB = headB;
	int lenB = 0;
	while (curB)
	{//计算链表B的长度
		lenB++;
		curB = curB->next;
	}

	//假设链表A比链表B长或相等情况
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;

	//链表A比链表B短的情况
	if (lenA < lenB)
	{
		longList = headB;
		shortList = headA;
	}

	int gap = abs(lenA - lenB);//求出两个链表的长度绝对值
	while (gap--)
	{//长的链表先走它们之间相差的长度
		longList = longList->next;
	}

	while (longList)
	{   //如果两个指针指向同一个空间，返回指向空间的地址
		if (longList == shortList)
			return longList;
		//如果没有，继续遍历
		longList = longList->next;
		shortList= shortList->next;
	}
	//如果遍历结束，还没有指向同一块空间，返回空指针
	return NULL;
}
int main()
{
	return 0;
}