#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
void moveZeroes_1(int* nums, int numsSize)
{
	//空数组
	if (nums == NULL || numsSize == 0)
		return;
	//将不为0的元素复制到arr数组中
	int* arr = (int*)malloc(sizeof(int)*numsSize);
	int cur = 0, i = 0;
	while (cur<numsSize)
	{
		if (nums[cur] != 0)
		{
			arr[i] = nums[cur];
			i++;
			cur++;
		}
		else
		{
			cur++;
		}
	}
	for (int j = i; j<numsSize; j++)
	{
		arr[j] = 0;
	}
	for (int i = 0; i < numsSize; i++)
	{
		nums[i] = arr[i];
	}
	free(arr);
	arr = NULL;
}
void moveZeroes(int* nums, int numsSize)
{
	if (nums == NULL || numsSize == 0)
		return;
	int cur = 0, prev = 0;
	while (cur < numsSize)
	{	//将不为0的元素进行移动
		if (nums[cur] != 0)
		{
			nums[prev] = nums[cur];
			cur++;
			prev++;
		}
		else
		{
			cur++;
		}
	}
	for (int i = prev; i < numsSize; i++)
	{
		nums[i] = 0;
	}
}
int main()
{
	int arr[] = { 0,1,2,3,0,12 };
	int size = sizeof(arr) / sizeof(arr[0]);
	moveZeroes(arr, size);
	for (int i = 0; i<size; i++)
	{
		//if (arr != NULL)
			printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}