#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
//打印
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// 插入排序
void InsertSort(int* arr, int n)
{	
	// [0, end]有序  end+1位置的值插入[0, end]，让[0, end+1]有序
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

}
// 堆排序
void AdjustDwon(int* arr, int n, int root)
{

}
void HeapSort(int* arr, int n)
{

}
// 冒泡排序
void BubbleSort(int* arr, int n)
{

}
// 快速排序
void QuickSort(int* arr, int left, int right)
{

}
// 归并排序
void MergeSort(int* arr, int n)
{

}