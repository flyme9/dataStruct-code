#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Stdlib.h>
int xorOperation(int n, int start) {
	int* arr = (int*)malloc(sizeof(int)*n);
	int ret = 0;
	for (int i = 0; i<n; i++)
	{
		arr[i] = start + 2*i;
		ret ^= arr[i];
	}
	free(arr);
	return ret;
}
int main()
{
	printf("%d ", xorOperation(5, 0));
	return 0;
}