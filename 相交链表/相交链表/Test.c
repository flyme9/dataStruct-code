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
	{//���������A�ĳ���
		lenA++;
		curA = curA->next;
	}

	struct ListNode* curB = headB;
	int lenB = 0;
	while (curB)
	{//��������B�ĳ���
		lenB++;
		curB = curB->next;
	}

	//��������A������B����������
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;

	//����A������B�̵����
	if (lenA < lenB)
	{
		longList = headB;
		shortList = headA;
	}

	int gap = abs(lenA - lenB);//�����������ĳ��Ⱦ���ֵ
	while (gap--)
	{//����������������֮�����ĳ���
		longList = longList->next;
	}

	while (longList)
	{   //�������ָ��ָ��ͬһ���ռ䣬����ָ��ռ�ĵ�ַ
		if (longList == shortList)
			return longList;
		//���û�У���������
		longList = longList->next;
		shortList= shortList->next;
	}
	//���������������û��ָ��ͬһ��ռ䣬���ؿ�ָ��
	return NULL;
}
int main()
{
	return 0;
}