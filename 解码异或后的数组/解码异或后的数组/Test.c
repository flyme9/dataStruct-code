#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
	*returnSize = encodedSize + 1;//新数组长度
	int* Arr = (int*)malloc(sizeof(int)*(encodedSize + 1));
	Arr[0] = first;
	for (int i = 1; i < *returnSize; i++)
	{//异或解码后存入Arr
		Arr[i] = encoded[i - 1] ^ Arr[i - 1];
	}
	return Arr;
}
int main()
{
	int enc[] = { 6,2,7,3 };
	int size = 0;
	int* arr = decode(enc, sizeof(enc) / sizeof(enc[0]), enc[0], &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}