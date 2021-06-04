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
	//�������Ԫ�ظ���
	*returnSize = matrixSize * (*matrixColSize);
	//����������
	int *res = (int*)calloc(*returnSize, sizeof(int));
	//�����������ұ߽�
	int up = 0, down = matrixSize - 1;
	int left = 0, right = matrixColSize[0] - 1;
	int index = 0;
	while (index < *returnSize)
	{
		//���ϱ�һ��Ԫ�ش��������У��������ң�
		for (int i = left; index < *returnSize && i <= right; i++)
		{
			res[index++] = matrix[up][i];
		}
		up++;
		//���ұ�һ��Ԫ�ش��������У��������£�
		for (int i = up; index < *returnSize && i <= down; i++)
		{
			res[index++] = matrix[i][right];
		}
		right--;
		//���±�һ��Ԫ�ش��������У���������
		for (int i = right; index < *returnSize && i >= left; i--)
		{
			res[index++] = matrix[down][i];
		}
		down--;
		//���ұ�һ��Ԫ�ش��������У��������ϣ�
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