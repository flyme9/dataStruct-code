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
			prev = cur;//如果不相等，prev指向cur的位置
					   //迭代
			cur = next;
			next = next->next;
		}
		else
		{
			while (next&&cur->val == next->val)
			{   //如果相等，next指针动，
				next = next->next;
			}
			if (prev)
			{
				prev->next = next;//prev链接next
			}
			else
			{//开头就相等的情况
				head = next;
			}
			while (cur != next)
			{   //释放节点
				struct ListNode* del = cur;
				cur = cur->next;//cur指向下一个节点
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