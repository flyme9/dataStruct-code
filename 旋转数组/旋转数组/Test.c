#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void movearry(int* arr, int left, int right)
{	//���ú���
	int tmp = 0;
	while (left<right)
	{	//����
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		//�������ָ��ָ����һ���±�
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k) 
{

	if (k >= numsSize)
		k %= numsSize;
	//��n>=���鳤��ʱ��֮����ת��֮ǰ����ͬ
	movearry(nums, numsSize-k, numsSize-1);//k֮��Ԫ������
	movearry(nums, 0, numsSize-k-1);//k֮ǰԪ������
	movearry(nums, 0, numsSize - 1);//������������
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	rotate(arr, sz, 5);
	for (int i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
}