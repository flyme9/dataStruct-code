#define _CRT_SECURE_NO_WARNINGS 1int CmpInt(const void* e1,const void* e2)
#include<stdlib.h>
#include<stdio.h>
int CmpInt(const void* e1,const void* e2)
{
return *(int*)e1 - *(int*)e2;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	//排序
	qsort(nums1, nums1Size, sizeof(int), CmpInt);
	qsort(nums2, nums2Size, sizeof(int), CmpInt);
	//用来记录新数组的长度
	*returnSize = 0;
	//两个指针
	int index1 = 0, index2 = 0;
	//开辟空间
	int len = nums1Size<nums2Size ? nums1Size : nums2Size;//返回最小值
	int* arr = (int*)malloc(sizeof(int)*len);
	if (arr != NULL)
	{
		while (index1<nums1Size&&index2<nums2Size)
		{   //数组1的值小于数组2
			if (nums1[index1]<nums2[index2])
				index1++;
			//数组1的值大于数组2
			else if (nums1[index1]>nums2[index2])
				index2++;
			else
			{   //当两个数组值相等时，表示相交
				arr[*returnSize] = nums1[index1];
				index1++;
				index2++;
				(*returnSize)++;
			}
		}
	}
	return arr;
}
int main()
{
	int arr1[] = { 1,2,2,1 };
	int arr2[] = { 2,2 };
	int size = 0;
	int* arr= intersect(arr1, 4, arr2, 2, &size);
	return 0;
}