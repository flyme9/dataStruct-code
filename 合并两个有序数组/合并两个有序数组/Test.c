#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int pnum1 = m - 1;//ָ��num1�������һ��Ԫ���±�
	int pnum2 = n - 1;//ָ��num2�������һ��Ԫ���±�
	int end = m + n - 1;//ָ��ϲ���num1�������һ��Ԫ���±�
	while (pnum2 >= 0 && pnum1 >= 0)
	{
		if (nums1[pnum1] <= nums2[pnum2])
		{
			//���nums2��������nums1�������һ���±���������
			nums1[end--] = nums2[pnum2--];
		}
		else
		{
			//���nums1��������nums2�������һ���±���������
			nums1[end--] = nums1[pnum1--];
		}
	}
	//���pnum1ָ���±�Ϊ0����ֱ�Ӹ�ֵ
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