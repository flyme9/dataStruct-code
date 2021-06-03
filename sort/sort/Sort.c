#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//��ӡ
void PrintArray(int* arr, int n)
{
	//��ӡ����
	for (int i = 0; i <n; i++)
	//��ӡ����
	//for(int i=n-1;i>=0;i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// ��������
void InsertSort(int* arr, int n)
{	
	//[0, end]����  end+1λ�õ�ֵ����[0, end]����[0, end+1]����
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
	//for (int i = 0; i < n-1; i++)
	//{
	//	int min = i;
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (arr[min] > arr[j])
	//		{	//���min����jλ�õ�ֵ�����н���
	//			Swap(&arr[min], &arr[j]);
	//		}
	//	}
	//}
	//�Ż���˫ָ��
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		Swap(&arr[begin], &arr[min]);
		if (begin == max)
			max = min;
		Swap(&arr[max], &arr[end]);
		begin++;
		end--;
	}
}
// ������
void AdjustDwon(int* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//�����ӿ�ʼ
	while (child < n)
	{
		//if (child + 1 < n&&arr[child + 1] < arr[child])
		//{
		//	child++;
		//}
		//if (arr[child] < arr[parent])
		//{
		//	//������ӱȸ���С������λ��
		//	Swap(&arr[child], &arr[parent]);
		//	parent = child;//������ָ���Ԫ�ظ�����
		//	child = parent * 2 + 1;//��һ������������
		//}
		//else
		//{
		//	break;
		//}

		//�����,ѡ�����Һ����д���Ǹ�
		if (child + 1 < n&&arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent])
		{
			//������ӱȸ��״󣬽���λ��
			Swap(&arr[child], &arr[parent]);
			parent = child;//������ָ���Ԫ�ظ�����
			child = parent * 2 + 1;//��һ������������
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//����
	//�����һ�������ķ�Ҷ�ڵ���������е���
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDwon(arr, n, i);
	//������,�����
	int end = n - 1;
	while (end > 0)
	{
		//������Ԫ�طŵ����
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end, 0);
		end--;
	}
}
// ð������
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)//����n-1��ð������
	{
		for (int j = 0; j < n - 1 - i; j++)//ÿ�˽���n-1-i�αȽ�
		{
			if (arr[j] > arr[j+1])
				//���ǰһ���Ⱥ�һ���󣬽��н���
				Swap(&arr[j], &arr[j+1]);
		}
	}
}
// ��������
void QuickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int pivot = arr[left];//�����׼��
		int leftCur = left+1;
		int rightCur = right;
		while (leftCur < rightCur)
		{
			if (arr[leftCur] > pivot)
			{
				//��߷űȻ�׼��С�������ұ߷űȻ�׼�������
				Swap(&arr[leftCur], &arr[rightCur]);
				rightCur--;
			}
			else
			{
				leftCur++;
			}
		}
		if (arr[leftCur] >= pivot)
			leftCur--;
		Swap(&arr[left], &arr[leftCur]);
		QuickSort(arr, left, leftCur);
		QuickSort(arr, rightCur, right);
	}
}
// �鲢����
void MergeSort(int* arr, int n)
{

}