#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode 
{
	int val;
	struct ListNode *next;
};
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* sortHead = head;//ȡԭ�����ͷ�ڵ���Ϊ�������ͷ
	struct ListNode* cur = head->next;//ָ��ԭ�������һ���ڵ�
	sortHead->next = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;//����cur��һ���ڵ�
										  //ͷ��
		if (cur->val <= sortHead->val)
		{
			cur->next = sortHead;//����ͷ��
			sortHead = cur;//cur��Ϊ�µ�ͷ
		}
		else
		{
			struct ListNode* sortPrev = sortHead;//����ָ��ǰһ���ڵ�
			struct ListNode* sortCur = sortPrev->next;//������������cur���бȽ�
													  //�м��
			while (sortCur)
			{
				if (cur->val <= sortCur->val)
				{   //��ǰһ���ڵ�󣬱Ⱥ�һ���ڵ�С����ڣ����в���
					sortPrev->next = cur;//����cur
					cur->next = sortCur;//cur����sortCur
					break;
				}
				else
				{   //������Ǵ���С�ڣ���������
					sortPrev = sortCur;
					sortCur = sortCur->next;
				}
			}
			//β��
			if (sortCur == NULL)
			{
				sortPrev->next = cur;
				cur->next = NULL;
			}
		}
		cur = next;
	}
	return sortHead;
}
int main()
{

	return 0;
}