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
		{	//如果prev和cur指向元素不相等，则将prev的元素给dst指向位置
			nums[dst] = nums[prev];
			prev++;
			cur++;
			dst++;
		}
		else
		{	//prev等于cur指向元素，则分别指向下一个元素进行对比
			cur++;
			prev++;
		}
	}
	//将最后一个元素给dst
	nums[dst] = nums[prev];
	dst++;
	prev++;
	return dst;//dst指向新数组的最后元素，表示数组长度
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