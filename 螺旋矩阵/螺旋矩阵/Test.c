#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define m 5
#define n 6
int main() 
{
	int maritx[m + 1][n + 1] = { 0 };  // ��1,1,��ʼ����0�У���0�в�ʹ��
	int now = 1;
	int U = 1, D = m, L = 1, R = n;  // �������ҵı߽�
	int i = 1, j = 1;    //�� ����1,1λ�ÿ�ʼ
	while (now <= m*n) 
	{
		//�ȴ�����д��
		while (now <= m*n && j < R) 
		{
			maritx[i][j] = now++;
			j++;
		}
		//���ұ��У����ϵ���д
		while (now <= m*n && i < D) 
		{
			maritx[i][j] = now++;
			i++;
		}
		//���һ�У����ҵ���
		while (now <= m*n && j > L) 
		{
			maritx[i][j] = now++;
			j--;
		}
		//�������У���������
		while (now <= m*n && i > U) 
		{
			maritx[i][j] = now++;
			i--;
		}
		U++, D--, L++, R--;
		i++;
		j++;

		//��ֹm = n �������ε�������һ������
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