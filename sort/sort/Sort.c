#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
//��ӡ
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// ��������
void InsertSort(int* arr, int n)
{	
	// [0, end]����  end+1λ�õ�ֵ����[0, end]����[0, end+1]����
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		//ָ���i��Ԫ��
		int tmp = arr[end + 1];
		//����end��һ��Ԫ�ص�ֵ
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{//endָ��Ԫ�ش���tmp����endָ���Ԫ������Ų
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
			//���endָ���Ԫ��С�ڵ���tmp������Ҫ����Ų��Ԫ��
		}
		//endΪ--��ķ���ֵ
		//�ҵ�λ�ú󣬲�����endָ��Ԫ�غ�һ��λ��
		arr[end + 1] = tmp;
	}
}
// ϣ������
void ShellSort(int* arr, int n)
{
	int gap=n;//���鳤��
	while (gap > 1)
	{
		gap /= 2;
		//���Ϊ1
		gap = gap / 3 + 1;
		//���Ϊ0����Ϊ1��Ϊ0ʱ����δ��ɣ�����+1
		//gap==1ʱ��Ϊֱ�Ӳ�������
		//gap>1ʱ��ΪԤ����

		//
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			//ָ���i��Ԫ��
			int tmp = arr[end + gap];
			//��������gap������Ԫ��
			while (end >= 0)
			{
				if (arr[end] > arr[end + gap])
				{	//Ų��Ԫ��
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			//��tmp��end+gapλ��
			arr[end + gap] = tmp;
		}
	}
}
// ѡ������
void SelectSort(int* arr, int n)
{

}
// ������
void AdjustDwon(int* arr, int n, int root)
{

}
void HeapSort(int* arr, int n)
{

}
// ð������
void BubbleSort(int* arr, int n)
{

}
// ��������
void QuickSort(int* arr, int left, int right)
{

}
// �鲢����
void MergeSort(int* arr, int n)
{

}