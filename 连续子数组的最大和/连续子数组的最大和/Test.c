#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize) 
{
	int ans = 0;
	int curSum = nums[0];
	for (int i = 1; i<numsSize; i++)
	{
		//如果我的位置的数加前一个位置的数和小于我自己，那么从我的位置重新开始
		if ((curSum + nums[i]) < nums[i])
			curSum = nums[i];
		//否则计算他们的和
		else
			curSum += nums[i];
		//如果ans的值小于和，将和给ans
		if (ans<curSum)
			ans = curSum;
	}
	return ans;
}
int main()
{
	int arr[] = { -2,1,-3,4,-1,2,1,-5,4 };
	printf("%d ", maxSubArray(arr, 9));
	return 0;
}