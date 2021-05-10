#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int pnum1 = m - 1;//指向num1数组最后一个元素下标
	int pnum2 = n - 1;//指向num2数组最后一个元素下标
	int end = m + n - 1;//指向合并后num1数组最后一个元素下标
	while (pnum2 >= 0 && pnum1 >= 0)
	{
		if (nums1[pnum1] <= nums2[pnum2])
		{
			//如果nums2的数大于nums1，则将最后一个下标放置这个数
			nums1[end--] = nums2[pnum2--];
		}
		else
		{
			//如果nums1的数大于nums2，则将最后一个下标放置这个数
			nums1[end--] = nums1[pnum1--];
		}
	}
	//如果pnum1指向下标为0，则直接赋值
	if (pnum1 < 0)
	{
		for (int i = 0; i < pnum2 + 1; i++)
		{
			nums1[i] = nums2[i];
		}
	}
}
int main()
{
	int arr1[50] = { 1,2,3 };
	int arr2[] = { 1,2,5,6 };
	merge(arr1, 3, 3, arr2, 4, 4);
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}