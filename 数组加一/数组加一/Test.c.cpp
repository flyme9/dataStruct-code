#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i]<9)
		{
			//���ָ���Ԫ��С��9����Ҫ��λ��ֱ�Ӽ�1
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
		//���ָ���Ԫ�ش���9������10����λ�� ��0
		digits[i] = 0;
	}
	//����Ԫ��ȫΪ9����������ٱ�digits��һ��λ�õ�����
	int* result = (int*)malloc(sizeof(int)*(digitsSize + 1));
	result[0] = 1;//����н�λ�����������һλ��Ϊ1��������ȫ����Ϊ0
	for (int i = 1; i<(digitsSize + 1); i++)
	{
		result[i] = 0;
	}
	*returnSize = digitsSize + 1;//����������ĳ���
	return result;
}
int main()
{
	int arr[] = { 9,9,9 };
	int size = 0;
	int* newarr = plusOne(arr, 3, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", newarr[i]);
	}
	return 0;
}