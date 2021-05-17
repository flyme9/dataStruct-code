#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	unsigned int data = 0;//�������
	unsigned int cnt = 0;//�ж��Ƿ�Ϊ������
	unsigned int flag = 0;//��λ

	struct ListNode* newlist = NULL;//�����֮���ֵ
	struct ListNode* listHead = NULL;//ָ������ͷ�ڵ�
	struct ListNode* listTemp = NULL;//ָ������β�ڵ�

	if ((l1 != NULL) && (l2 != NULL))
	{
		do
		{
			data = flag;
			if (l1 != NULL)
			{
				data = data + l1->val;//����1��data��falg���
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				data = data + l2->val;//������1��Ӻ�data������1+��λ��ֵ���ں�����2���
				l2 = l2->next;
			}
			flag = data / 10;//�жϽ�λ
			newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newlist != NULL)
			{
				newlist->next = NULL;
				newlist->val = data % 10;//���ֵ
				if (cnt == 0)
				{//�������Ϊ��
					listHead = newlist;
					listTemp = listHead;
				}
				else
				{//��һ�����Ͻڵ�
					listTemp->next = newlist;//ָ��ֵ�ĵ�ַ
					listTemp = listTemp->next;//ָ����β�ڵ�
				}
			}
			cnt++;
		} while ((l1 != NULL) || (l2 != NULL));
		if (flag == 1)
		{//����������н�λ������һ���ռ�
			cnt++;
			newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newlist != NULL)
			{
				newlist->next = NULL;
				newlist->val = 1;//��Ž�λֵ
				listTemp->next = newlist;//ָ����β�ڵ�
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