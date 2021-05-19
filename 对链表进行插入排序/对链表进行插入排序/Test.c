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
	struct ListNode* sortHead = head;//取原链表的头节点作为新链表的头
	struct ListNode* cur = head->next;//指向原链表的下一个节点
	sortHead->next = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;//保存cur下一个节点
										  //头插
		if (cur->val <= sortHead->val)
		{
			cur->next = sortHead;//进行头插
			sortHead = cur;//cur成为新的头
		}
		else
		{
			struct ListNode* sortPrev = sortHead;//用于指向前一个节点
			struct ListNode* sortCur = sortPrev->next;//用于新链表与cur进行比较
													  //中间插
			while (sortCur)
			{
				if (cur->val <= sortCur->val)
				{   //比前一个节点大，比后一个节点小或等于，进行插入
					sortPrev->next = cur;//链接cur
					cur->next = sortCur;//cur链接sortCur
					break;
				}
				else
				{   //如果不是大于小于，继续遍历
					sortPrev = sortCur;
					sortCur = sortCur->next;
				}
			}
			//尾插
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