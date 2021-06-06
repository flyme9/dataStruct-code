#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize) 
{
	int ans = 0;
	int curSum = nums[0];
	for (int i = 1; i<numsSize; i++)
	{
		//����ҵ�λ�õ�����ǰһ��λ�õ�����С�����Լ�����ô���ҵ�λ�����¿�ʼ
		if ((curSum + nums[i]) < nums[i])
			curSum = nums[i];
		//����������ǵĺ�
		else
			curSum += nums[i];
		//���ans��ֵС�ںͣ����͸�ans
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