#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//找出单身狗
int* SingleNumber(int* nums, int numssize, int* returnsize)
{
	int ret = 0;
	//ret得到的是两个出现一次的数异或后的结果
	for (int i = 0; i < numssize; ++i)
	{	
		ret ^= nums[i];
	}
	int m = 0;
	//找出ret 第m位为1的数
	while (m < 32)
	{	
		if (m&(1 << m))
			break;
		else
			m++;
	}
	//分离出x1和x2
	int x1 = 0, x2 = 0;
	for (int i = 0; i < numssize; i++)
	{
		if (nums[i] & (1 << m))
			x1 ^= nums[i];
		else
			x2 ^= nums[i];
	}
	int* retArr = (int*)malloc(sizeof(int) * 2);
	retArr[0] = x1;
	retArr[1] = x2;
	*returnsize = 2;
	return retArr;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7};
	int sz = 0;
	int* Arr = SingleNumber(arr, sizeof(arr) / sizeof(arr[0]), &sz);
	for (int i = sz-1; i >=0; i--)
	{
		printf("%d ", Arr[i]);
	}
	return 0;
}