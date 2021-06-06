#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int intCmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int majorityElement(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), intCmp);
	int count = 0, half = numsSize >> 1;
	int prev = 0, cur = 1;
	while (cur<numsSize)
	{
		if (nums[prev] == nums[cur])
		{
			count++;
			cur++;
		}
		else
		{
			prev++;
			cur++;
		}
		if (count>half)
			break;
	}
	return nums[prev];
}
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	printf("%d ", majorityElement(arr, 6));
	return 0;
}