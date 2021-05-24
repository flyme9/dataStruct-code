#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i]<9)
		{
			//如果指向的元素小于9，不要进位，直接加1
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
		//如果指向的元素大于9，等于10，该位置 置0
		digits[i] = 0;
	}
	//数组元素全为9的情况，开辟比digits大一个位置的数组
	int* result = (int*)malloc(sizeof(int)*(digitsSize + 1));
	result[0] = 1;//最后有进位，将新数组第一位置为1，将后面全部置为0
	for (int i = 1; i<(digitsSize + 1); i++)
	{
		result[i] = 0;
	}
	*returnSize = digitsSize + 1;//返回新数组的长度
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