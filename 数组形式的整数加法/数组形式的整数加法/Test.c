#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>	
#include<stdlib.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
	int kSize = 0;
	int kNum = k;//����k
				 //���k�ĳ���
	while (kNum)
	{
		++kSize;
		kNum /= 10;
	}
	//�ж�˭�ĳ��ȳ�
	int len = numSize > kSize ? numSize : kSize;
	//���ٳ��ĳ���+1���ڴ�ռ�
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));
	int numi = numSize - 1;//ָ���������һ��Ԫ��
	int reti = 0;//��¼���ٵĿռ����˶��ٸ�Ԫ��
	int next = 0;//��¼��λ
	while (len--)
	{
		int a = 0;
		if (numi >= 0)
		{
			//�����������k���ȶ�ʱ�������Խ�������Խ����õ���������Ǽ���������
			a = num[numi];
			--numi;
		}
		int ret = a + k % 10 + next;
		k /= 10;//�õ�k����һλ
		if (ret>9)
		{   //��Ӻ��н�λ�����
			ret -= 10;
			next = 1;
		}
		else
			next = 0;
		//��Ӻ󲻽�λ�����
		//��������
		retArr[reti] = ret;
		++reti;
	}
	if (next == 1)
	{
		retArr[reti] = 1;
		reti++;
	}
	//��ת����
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