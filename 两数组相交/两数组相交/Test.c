#define _CRT_SECURE_NO_WARNINGS 1int CmpInt(const void* e1,const void* e2)
#include<stdlib.h>
#include<stdio.h>
int CmpInt(const void* e1,const void* e2)
{
return *(int*)e1 - *(int*)e2;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	//����
	qsort(nums1, nums1Size, sizeof(int), CmpInt);
	qsort(nums2, nums2Size, sizeof(int), CmpInt);
	//������¼������ĳ���
	*returnSize = 0;
	//����ָ��
	int index1 = 0, index2 = 0;
	//���ٿռ�
	int len = nums1Size<nums2Size ? nums1Size : nums2Size;//������Сֵ
	int* arr = (int*)malloc(sizeof(int)*len);
	if (arr != NULL)
	{
		while (index1<nums1Size&&index2<nums2Size)
		{   //����1��ֵС������2
			if (nums1[index1]<nums2[index2])
				index1++;
			//����1��ֵ��������2
			else if (nums1[index1]>nums2[index2])
				index2++;
			else
			{   //����������ֵ���ʱ����ʾ�ཻ
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