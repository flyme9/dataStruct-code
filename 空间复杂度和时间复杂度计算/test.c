#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{//这里需要执行N次，嵌套for语句执行N次，所以执行N^2次
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{//执行2*N次
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{//执行10次
//		++count;
//	}
//	printf("%d\n", count);
//}
//所以执行：N*N+2*N+10但是当N较大时，2*N+10对结果影响不大，
//所以用大O渐进法表示为O(N)

//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	for (int i = 0; i<numsSize; i++)
//	{//执行次数N次
//		x ^= nums[i];//先和数组各个元素异或并保存到x中
//	}
//	for (int j = 0; j <= numsSize; j++)
//	{//执行次数N+1次
//		x ^= j;//通过和0-N个数组元素异或，得到缺少的元素值
//	}
//	return x;
//}
////执行次数N+1次，1对结果影响不大，舍去，所以时间复杂度为O（N）
//int main()
//{
//	int arr[] = {1,0,3,4,5,6};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = missingNumber(arr, sz);
//	printf("%d\n", ret);
//	return 0;
//}

//void movearry(int* arr, int left, int right)
//{
//	int tmp = 0;
//	while (left<right)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void rotate(int* nums, int numsSize, int k) {
//	k %= numsSize;
//	movearry(nums, 0, numsSize - 1);
//	movearry(nums, 0, k - 1);
//	movearry(nums, k, numsSize - 1);
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	rotate(arr, sz, 3);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	
//}

//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{//执行2*N次
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{//执行10次
//		++count;
//	}
//	printf("%d\n", count);
//}
////共执行2*N+10次，2倍和10对结果影响不大，舍去，O(N)
//int main()
//{
//	Func2(1000);
//	return 0;
//}

//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{//执行M次
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{//执行N次
//		++count;
//	}
//	printf("%d\n", count);
//}
////当M远大于N时，执行M+N次，N对结果影响不大，O(M)
////当N远大于M时，执行M+N次，M对结果影响不大，O(N)
////当M和N相近时，执行M+N次，O(M+N)
////时间复杂度看最坏情况：O(M+N)
//int main()
//{
//	Func3(10000, 100000);
//	return 0;
//}

//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{//执行100次，100
//		++count;
//	}
//	printf("%d\n", count);
//}
////执行100次，100是常数，常数时间复杂度表示为O(1)
//int main()
//{
//	Func4(1000);
//	return 0;
//}

//const char * strchr(const char * str, char character)
//{
//	while (*str != '\0')
//	{
//		if (*str == character)
//			return str;
//		++str;
//	}
//	return NULL;
//}
////如果一次就找到时间复杂度为O（1）
////如果找到最后找到或找不到，时间复杂度为O（N）
//int main()
//{
//	char arr1[] = "abcdef";
//	printf(strchr(arr1, 'f'));
//	return 0;
//}

//void Swap(int* des,int* src)
//{
//	if (des > src)
//	{
//		int tmp = *des;
//		*des = *src;
//		*src = tmp;
//	}
//}
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{//执行N次
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{//执行N*（N+1）/2次：等差数列各项和
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		//执行第一条for语句，则是N次
//		if (exchange == 0)
//			break;
//	}
//}
////最好情况：执行了N次O(N)
////最坏情况：N*（N+1）/2 ==> (N^2+N)/2 次，+N  /2对结果影响不大
////所以表示为：O(N^2)
////时间复杂度看最坏：O(N^2)
//int main()
//{
//	int arr1[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr1) / sizeof(arr1);
//	BubbleSort(arr1, sz);
//	printf("%d ", arr1);
//	return 0;
//}

//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}
////最好情况：中位数就是要查找的数O（1）
////最坏情况：每次查找范围缩小一半，知道只剩最后一个元素
////O（logN）==>logN表示2为底，N为对数

//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1)*N;
//}
////函数递归N次，所以时间复杂度为O（N）



//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;						//开辟了N+1个空间
//	long long * fibArray = (long long *)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}
////空间复杂度：3+N+1个变量，3和1对结果影响不大舍去，O（N）


long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1)*N;
}
//创建了一个变量，但是递归调用需要建立栈帧，建立了N次栈帧，
//所以空间复杂度为O（N）