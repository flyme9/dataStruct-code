#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	//1 2 3
	//4 5 6
	//7 8 9
	//1 2 3 6 9 8 7 4 5
	if (matrixSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	//计算矩阵元素个数
	*returnSize = matrixSize * (*matrixColSize);
	//开辟新数组
	int *res = (int*)calloc(*returnSize, sizeof(int));
	//矩阵上下左右边界
	int up = 0, down = matrixSize - 1;
	int left = 0, right = matrixColSize[0] - 1;
	int index = 0;
	while (index < *returnSize)
	{
		//将上边一行元素存入数组中（从左至右）
		for (int i = left; index < *returnSize && i <= right; i++)
		{
			res[index++] = matrix[up][i];
		}
		up++;
		//将右边一列元素存入数组中（从上至下）
		for (int i = up; index < *returnSize && i <= down; i++)
		{
			res[index++] = matrix[i][right];
		}
		right--;
		//将下边一行元素存入数组中（从右至左）
		for (int i = right; index < *returnSize && i >= left; i--)
		{
			res[index++] = matrix[down][i];
		}
		down--;
		//将右边一列元素存入数组中（从下至上）
		for (int i = down; index < *returnSize && i >= up; i--)
		{
			res[index++] = matrix[i][left];
		}
		left++;
	}
	return res;
}
int main()
{
	int* arr = (int*)malloc(sizeof(int) * 9);
	for (int i = 0; i < 9; i++)
	{
		arr[i] = i;
	}
	int size = 0;
	int colsize = 3;
	int* res = spiralOrder(&arr, 3, &colsize, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(res + i));
	}
	return 0;
}