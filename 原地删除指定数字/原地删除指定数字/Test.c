#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeElement(int* nums, int numssize, int val)
{
	int src = 0, dst = 0;//
	while (src < numssize)
	{
		if (nums[src] != val)
		{	//���srcָ���Ԫ�ز�����val����srcָ��Ԫ�ظ���des��Ȼ��ͬʱָ����һ��Ԫ��
			nums[dst] = nums[src];
			dst++;
			src++;
		}
		else
			src++;
		//���srcָ��Ԫ�ص���val����ָ����һ��Ԫ�أ�dst����
	}
	return dst;//ѭ��������dstָ�����������Ԫ��
}
int main()
{
	int arr[] = { 2,3,2,3,3};
	int val = 3;
	int arrsize = sizeof(arr) / sizeof(arr[0]);
	int ret = removeElement(arr, arrsize, val);
	for (int i = 0; i < ret; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}