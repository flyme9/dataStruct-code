#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define m 5
#define n 6
int main() 
{
	int maritx[m + 1][n + 1] = { 0 };  // 从1,1,开始，第0行，第0列不使用
	int now = 1;
	int U = 1, D = m, L = 1, R = n;  // 上下左右的边界
	int i = 1, j = 1;    //从 数组1,1位置开始
	while (now <= m*n) 
	{
		//先从左到右写行
		while (now <= m*n && j < R) 
		{
			maritx[i][j] = now++;
			j++;
		}
		//最右边列，从上到下写
		while (now <= m*n && i < D) 
		{
			maritx[i][j] = now++;
			i++;
		}
		//最后一行，从右到左
		while (now <= m*n && j > L) 
		{
			maritx[i][j] = now++;
			j--;
		}
		//最后左边列，从下往上
		while (now <= m*n && i > U) 
		{
			maritx[i][j] = now++;
			i--;
		}
		U++, D--, L++, R--;
		i++;
		j++;

		//防止m = n 是正方形的情况最后一个数字
		if (now == m*n) {
			maritx[i][j] = now++;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d\t", maritx[i][j]);
		}
		printf("\n");
	}

	return 0;
}