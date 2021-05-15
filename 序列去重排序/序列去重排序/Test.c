#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0, *arr = 0, max = 0, m = 0, count = 0;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	//数组开辟n+1个空间
	if (arr != NULL)
	{
		for (int i = 0; i<n; i++)
		{
			scanf("%d", &m);
			if (max < m)
			{
				max = m;
			}
			arr[m] = m;
		}
		for (int i = 1; i <= n; i++)
		{
			if (arr[i])
				printf("%d ", arr[i]);
		}
	}
	return 0;
}