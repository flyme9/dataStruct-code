#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int DisNumber(int* nums,int numssize)
{
	int x = 0;
	//x������ÿ��Ԫ����򣬵õ�������������Ľ��
	for (int i = 0; i < numssize; i++)
	{
		x ^= nums[i];
	}
	//x��0-N������������յõ���ʧ������
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