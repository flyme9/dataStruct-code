#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{//������Ҫִ��N�Σ�Ƕ��for���ִ��N�Σ�����ִ��N^2��
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{//ִ��2*N��
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{//ִ��10��
//		++count;
//	}
//	printf("%d\n", count);
//}
//����ִ�У�N*N+2*N+10���ǵ�N�ϴ�ʱ��2*N+10�Խ��Ӱ�첻��
//�����ô�O��������ʾΪO(N)

//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	for (int i = 0; i<numsSize; i++)
//	{//ִ�д���N��
//		x ^= nums[i];//�Ⱥ��������Ԫ����򲢱��浽x��
//	}
//	for (int j = 0; j <= numsSize; j++)
//	{//ִ�д���N+1��
//		x ^= j;//ͨ����0-N������Ԫ����򣬵õ�ȱ�ٵ�Ԫ��ֵ
//	}
//	return x;
//}
////ִ�д���N+1�Σ�1�Խ��Ӱ�첻����ȥ������ʱ�临�Ӷ�ΪO��N��
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
//	{//ִ��2*N��
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{//ִ��10��
//		++count;
//	}
//	printf("%d\n", count);
//}
////��ִ��2*N+10�Σ�2����10�Խ��Ӱ�첻����ȥ��O(N)
//int main()
//{
//	Func2(1000);
//	return 0;
//}

//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{//ִ��M��
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{//ִ��N��
//		++count;
//	}
//	printf("%d\n", count);
//}
////��MԶ����Nʱ��ִ��M+N�Σ�N�Խ��Ӱ�첻��O(M)
////��NԶ����Mʱ��ִ��M+N�Σ�M�Խ��Ӱ�첻��O(N)
////��M��N���ʱ��ִ��M+N�Σ�O(M+N)
////ʱ�临�Ӷȿ�������O(M+N)
//int main()
//{
//	Func3(10000, 100000);
//	return 0;
//}

//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{//ִ��100�Σ�100
//		++count;
//	}
//	printf("%d\n", count);
//}
////ִ��100�Σ�100�ǳ���������ʱ�临�Ӷȱ�ʾΪO(1)
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
////���һ�ξ��ҵ�ʱ�临�Ӷ�ΪO��1��
////����ҵ�����ҵ����Ҳ�����ʱ�临�Ӷ�ΪO��N��
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
//	{//ִ��N��
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{//ִ��N*��N+1��/2�Σ��Ȳ����и����
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		//ִ�е�һ��for��䣬����N��
//		if (exchange == 0)
//			break;
//	}
//}
////��������ִ����N��O(N)
////������N*��N+1��/2 ==> (N^2+N)/2 �Σ�+N  /2�Խ��Ӱ�첻��
////���Ա�ʾΪ��O(N^2)
////ʱ�临�Ӷȿ����O(N^2)
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
////����������λ������Ҫ���ҵ���O��1��
////������ÿ�β��ҷ�Χ��Сһ�룬֪��ֻʣ���һ��Ԫ��
////O��logN��==>logN��ʾ2Ϊ�ף�NΪ����

//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1)*N;
//}
////�����ݹ�N�Σ�����ʱ�临�Ӷ�ΪO��N��



//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;						//������N+1���ռ�
//	long long * fibArray = (long long *)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}
////�ռ临�Ӷȣ�3+N+1��������3��1�Խ��Ӱ�첻����ȥ��O��N��


long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1)*N;
}
//������һ�����������ǵݹ������Ҫ����ջ֡��������N��ջ֡��
//���Կռ临�Ӷ�ΪO��N��