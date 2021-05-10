#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int removeElement(int* nums, int numssize, int val)
{
	int src = 0, dst = 0;//
	while (src < numssize)
	{
		if (nums[src] != val)
		{	//如果src指向的元素不等于val，则将src指向元素赋给des，然后同时指向下一个元素
			nums[dst] = nums[src];
			dst++;
			src++;
		}
		else
			src++;
		//如果src指向元素等于val，则指向下一个元素，dst不变
	}
	return dst;//循环结束，dst指向新数组最后元素
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