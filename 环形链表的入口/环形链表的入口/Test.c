#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast = head, *slow = head;
	while (fast&&fast->next)
	{
		slow = slow->next;//��ָ����һ��
		fast = fast->next->next;//��ָ��������
								//�Ƶ����ۣ�һ��ָ��������㿪ʼ�ߣ�һ��������ͷ��
		if (fast == slow)
		{//��ָ�����ָ������
			struct ListNode* meet = slow;
			while (head != meet)
			{
				head = head->next;
				meet = meet->next;
			}
			return meet;
		}
	}
	return NULL;
}
int main()
{
	return 0;
}