#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void movearry(int* arr, int left, int right)
{	//逆置函数
	int tmp = 0;
	while (left<right)
	{	//交换
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		//交换完后，指针指向下一个下标
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k) 
{

	if (k >= numsSize)
		k %= numsSize;
	//当n>=数组长度时，之后旋转与之前的相同
	movearry(nums, numsSize-k, numsSize-1);//k之后元素逆置
	movearry(nums, 0, numsSize-k-1);//k之前元素逆置
	movearry(nums, 0, numsSize - 1);//数组整体逆置
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	rotate(arr, sz, 5);
	for (int i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
}