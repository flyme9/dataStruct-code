#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//打印
void PrintArray(int* arr, int n)
{
	//打印升序
	for (int i = 0; i <n; i++)
	//打印降序
	//for(int i=n-1;i>=0;i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// 插入排序
void InsertSort(int* arr, int n)
{	
	//[0, end]有序  end+1位置的值插入[0, end]，让[0, end+1]有序
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		//指向第i个元素
		int tmp = arr[end + 1];
		//保存end后一个元素的值
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{//end指向元素大于tmp，则将end指向的元素往后挪
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
			//如果end指向的元素小于等于tmp，则不需要进行挪动元素
		}
		//end为--后的返回值
		//找到位置后，插入在end指向元素后一个位置
		arr[end + 1] = tmp;
	}
}
// 希尔排序
void ShellSort(int* arr, int n)
{
	int gap=n;//分组长度
	while (gap > 1)
	{
		gap /= 2;
		//最后为1
		gap = gap / 3 + 1;
		//最后为0或者为1，为0时排序未完成，所以+1
		//gap==1时，为直接插入排序
		//gap>1时，为预排序

		//
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			//指向第i个元素
			int tmp = arr[end + gap];
			//保存这组gap步长的元素
			while (end >= 0)
			{
				if (arr[end] > arr[end + gap])
				{	//挪动元素
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			//将tmp给end+gap位置
			arr[end + gap] = tmp;
		}
	}
}
// 选择排序
void SelectSort(int* arr, int n)
{
	//for (int i = 0; i < n-1; i++)
	//{
	//	int min = i;
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (arr[min] > arr[j])
	//		{	//如果min大于j位置的值，进行交换
	//			Swap(&arr[min], &arr[j]);
	//		}
	//	}
	//}
	//优化，双指针
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
// 堆排序
void AdjustDwon(int* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//从左孩子开始
	while (child < n)
	{
		//if (child + 1 < n&&arr[child + 1] < arr[child])
		//{
		//	child++;
		//}
		//if (arr[child] < arr[parent])
		//{
		//	//如果孩子比父亲小，交换位置
		//	Swap(&arr[child], &arr[parent]);
		//	parent = child;//将孩子指向的元素给父亲
		//	child = parent * 2 + 1;//下一棵子树的左孩子
		//}
		//else
		//{
		//	break;
		//}

		//建大堆,选出左右孩子中大的那个
		if (child + 1 < n&&arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent])
		{
			//如果孩子比父亲大，交换位置
			Swap(&arr[child], &arr[parent]);
			parent = child;//将孩子指向的元素给父亲
			child = parent * 2 + 1;//下一棵子树的左孩子
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//建堆
	//从最后一颗子树的非叶节点的子树进行调整
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDwon(arr, n, i);
	//排升序,建大堆
	int end = n - 1;
	while (end > 0)
	{
		//将最大的元素放到最后
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end, 0);
		end--;
	}
}
// 冒泡排序
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)//进行n-1趟冒泡排序
	{
		for (int j = 0; j < n - 1 - i; j++)//每趟进行n-1-i次比较
		{
			if (arr[j] > arr[j+1])
				//如果前一个比后一个大，进行交换
				Swap(&arr[j], &arr[j+1]);
		}
	}
}
// 快速排序
void QuickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int pivot = arr[left];//保存基准数
		int leftCur = left+1;
		int rightCur = right;
		while (leftCur < rightCur)
		{
			if (arr[leftCur] > pivot)
			{
				//左边放比基准数小的数，右边放比基准数大的数
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
// 归并排序
void MergeSort(int* arr, int n)
{

}