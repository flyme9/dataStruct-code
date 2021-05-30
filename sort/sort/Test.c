#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void TestInsertSort()
{
	int arr[] = { 3,2,1,6,5,4,9,8,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	PrintArray(arr, size);
}
void TestShellSort()
{
	int arr[] = { 3,2,1,6,5,4,9,8,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	PrintArray(arr, size);
}
int main()
{
	TestInsertSort();
	TestShellSort();
	return 0;
}