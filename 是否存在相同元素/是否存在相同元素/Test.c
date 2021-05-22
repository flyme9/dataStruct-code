#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int CmpInt(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
bool containsDuplicate(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), CmpInt);
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}
int main()
{
	int arr[] = { 1,2,3,1 };
	bool ret = containsDuplicate(arr, 4);
	printf("%d ", ret);
	return 0;
}