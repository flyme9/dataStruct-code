#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* arr = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i<numsSize; i++)
	{
		for (int j = 0; j<numsSize; j++)
		{
			if (target == nums[i] + nums[j])
			{
				arr[0] = j;
				arr[1] = i;
				break;
			}
		}
	}
	*returnSize = 2;
	return arr;
}
int main()
{
	int arr[] = { 2,7,11,15 };
	int size = 0;
	int* newArr = twoSum(arr, sizeof(arr) / sizeof(arr[0]), 9, &size);
	printf("%d %d\n", newArr[0], newArr[1]);
	return 0;
}