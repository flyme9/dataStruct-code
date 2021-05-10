#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int DisNumber(int* nums,int numssize)
{
	int x = 0;
	//x和数组每个元素异或，得到所有数组异或后的结果
	for (int i = 0; i < numssize; i++)
	{
		x ^= nums[i];
	}
	//x和0-N的数字异或，最终得到消失的数字
	for (int j = 0; j <= numssize; j++)
	{
		x ^= j;
	}
	return x;
}
int main()
{
	int arr[] = { 1,2,3,4,0,6,7,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("%d ", DisNumber(arr, size));
return 0;
}