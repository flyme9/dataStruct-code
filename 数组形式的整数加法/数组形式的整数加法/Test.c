#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>	
#include<stdlib.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
	int kSize = 0;
	int kNum = k;//保存k
				 //求出k的长度
	while (kNum)
	{
		++kSize;
		kNum /= 10;
	}
	//判断谁的长度长
	int len = numSize > kSize ? numSize : kSize;
	//开辟长的长度+1个内存空间
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));
	int numi = numSize - 1;//指向数组最后一个元素
	int reti = 0;//记录开辟的空间存放了多少个元素
	int next = 0;//记录进位
	while (len--)
	{
		int a = 0;
		if (numi >= 0)
		{
			//当数组比数字k长度短时，会出现越界情况，越界后拿到随机数，是计算结果错误，
			a = num[numi];
			--numi;
		}
		int ret = a + k % 10 + next;
		k /= 10;//拿到k的下一位
		if (ret>9)
		{   //相加后有进位的情况
			ret -= 10;
			next = 1;
		}
		else
			next = 0;
		//相加后不进位的情况
		//存入数组
		retArr[reti] = ret;
		++reti;
	}
	if (next == 1)
	{
		retArr[reti] = 1;
		reti++;
	}
	//反转数组
	int left = 0, right = reti - 1;
	while (left < right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = tmp;
		left++;
		right--;
	}
	*returnSize = reti;
	return retArr;
}
int main()
{
	int arr[] = { 1,2,0,0 };
	int k = 34;
	int size = 0;
	int* Arr = addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), k, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", Arr[i]);
	}
	return 0;
}