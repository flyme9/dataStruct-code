#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeDuplicates(int* nums, int numssize)
{
	if (numssize == 0)
		return 0;
	int prev = 0, cur = 1, dst = 0;
	while (cur < numssize)
	{
		if (nums[prev] != nums[cur])
		{	//���prev��curָ��Ԫ�ز���ȣ���prev��Ԫ�ظ�dstָ��λ��
			nums[dst] = nums[prev];
			prev++;
			cur++;
			dst++;
		}
		else
		{	//prev����curָ��Ԫ�أ���ֱ�ָ����һ��Ԫ�ؽ��жԱ�
			cur++;
			prev++;
		}
	}
	//�����һ��Ԫ�ظ�dst
	nums[dst] = nums[prev];
	dst++;
	prev++;
	return dst;//dstָ������������Ԫ�أ���ʾ���鳤��
}
int main()
{
	int arr[] = { 1,2,3,3,4,5,6,8,9,9,9,9 };
	int ret = removeDuplicates(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < ret; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}