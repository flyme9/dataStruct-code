#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode 
{
	int val;
	struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = cur->next;

	while (next)
	{
		if (cur->val != next->val)
		{
			prev = cur;//�������ȣ�prevָ��cur��λ��
					   //����
			cur = next;
			next = next->next;
		}
		else
		{
			while (next&&cur->val == next->val)
			{   //�����ȣ�nextָ�붯��
				next = next->next;
			}
			if (prev)
			{
				prev->next = next;//prev����next
			}
			else
			{//��ͷ����ȵ����
				head = next;
			}
			while (cur != next)
			{   //�ͷŽڵ�
				struct ListNode* del = cur;
				cur = cur->next;//curָ����һ���ڵ�
				free(del);
			}
			if (next)
				next = cur->next;
		}
	}
	return head;
}
int main()
{

	return 0;
}