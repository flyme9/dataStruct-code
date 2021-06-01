#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;//存储数据
	int top;//栈顶
	int capacity;//容量
}Stack;
//初始化
void StackInit(Stack* ps);
//栈销毁
void StackDestroy(Stack* ps);
//入栈
void StackPush(Stack* ps, STDataType x);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
STDataType StackTop(Stack* ps);
//获取栈中有效元素个数
int StackSize(Stack* ps);
//检测栈是否为空
bool StackEmpty(Stack* ps);
//初始化
void StackInit(Stack* ps)
{	//初始化给定四个字节空间
	ps->arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	//判断空间开辟是否成功
	if (ps->arr == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	memset(ps->arr, 0, sizeof(STDataType) * 4);
	ps->top = 0;
	ps->capacity = 4;
}//栈销毁
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);//释放
	ps->arr = NULL;//置空指针
	ps->top = ps->capacity = 0;//置0
}
//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{//空间满了要扩容
		STDataType* tmp = realloc(ps->arr, sizeof(STDataType) * 2 * ps->capacity);
		//判断内存是否开辟成功
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->arr = tmp;
			ps->capacity *= 2;
		}
	}
	ps->arr[ps->top] = x;
	ps->top++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	//assert(!StackEmpty(ps));//栈空了，调用报错，终止程序
	if (StackEmpty(ps))
		return;
	ps->top--;
}
//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	//assert(!StackEmpty(ps));//栈空了，调用报错，终止程序
	if (StackEmpty(ps))
		return -1;
	return ps->arr[ps->top - 1];
}
//获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//检测栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;//等于0为空，非0表示栈内有数据
}
typedef struct {
	Stack pushST;//入队栈
	Stack popST;//出队栈
} CQueue;


CQueue* cQueueCreate() {
	//创建初始化队列
	CQueue* ps = (CQueue*)malloc(sizeof(CQueue));
	StackInit(&ps->pushST);
	StackInit(&ps->popST);
	return ps;
}

void cQueueAppendTail(CQueue* obj, int value) {
	//数据存到入队栈
	StackPush(&obj->pushST, value);
}

int cQueueDeleteHead(CQueue* obj) {
	if (StackEmpty(&obj->popST))
	{//如果出队栈为空，则将入队栈的数据倒进去
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	//获取出队栈的栈顶元素
	int top = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return top;
}

void cQueueFree(CQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}
int fib(int n) {
	int* arr = (int*)malloc(sizeof(int)*n + 1);
	if (arr != NULL)
	{
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
	}
	return arr[n];
}
int* exchange(int* nums, int numsSize, int* returnSize) {
	if (nums == NULL || numsSize == 0)
	{
		return NULL;
	}
	int* oddArr = (int*)malloc(sizeof(int)*numsSize);
	int* evenArr = (int*)malloc(sizeof(int)*numsSize);
	int cur = 0, countOdd = 0, countEven = 0;
	while (cur<numsSize)
	{
		if (nums[cur] % 2 == 0)
		{
			oddArr[countOdd] = nums[cur];
			countOdd++;
			cur++;
		}
		else
		{
			evenArr[countEven] = nums[cur];
			countEven++;
			cur++;
		}
	}
	while (countEven<numsSize)
	{
		evenArr[countEven + 1] = oddArr[countOdd];
		countEven++;
		countOdd--;
	}
	return evenArr;
}
int main() 
{
	CQueue* q = cQueueCreate();
	cQueueAppendTail(q, 3);
	cQueueDeleteHead(q);
	cQueueDeleteHead(q);
	int i= fib(5);
	printf("%d ", i);
}