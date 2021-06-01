#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;//�洢����
	int top;//ջ��
	int capacity;//����
}Stack;
//��ʼ��
void StackInit(Stack* ps);
//ջ����
void StackDestroy(Stack* ps);
//��ջ
void StackPush(Stack* ps, STDataType x);
//��ջ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);
//��ʼ��
void StackInit(Stack* ps)
{	//��ʼ�������ĸ��ֽڿռ�
	ps->arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	//�жϿռ俪���Ƿ�ɹ�
	if (ps->arr == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	memset(ps->arr, 0, sizeof(STDataType) * 4);
	ps->top = 0;
	ps->capacity = 4;
}//ջ����
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);//�ͷ�
	ps->arr = NULL;//�ÿ�ָ��
	ps->top = ps->capacity = 0;//��0
}
//��ջ
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{//�ռ�����Ҫ����
		STDataType* tmp = realloc(ps->arr, sizeof(STDataType) * 2 * ps->capacity);
		//�ж��ڴ��Ƿ񿪱ٳɹ�
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
//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	//assert(!StackEmpty(ps));//ջ���ˣ����ñ�����ֹ����
	if (StackEmpty(ps))
		return;
	ps->top--;
}
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	//assert(!StackEmpty(ps));//ջ���ˣ����ñ�����ֹ����
	if (StackEmpty(ps))
		return -1;
	return ps->arr[ps->top - 1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;//����0Ϊ�գ���0��ʾջ��������
}
typedef struct {
	Stack pushST;//���ջ
	Stack popST;//����ջ
} CQueue;


CQueue* cQueueCreate() {
	//������ʼ������
	CQueue* ps = (CQueue*)malloc(sizeof(CQueue));
	StackInit(&ps->pushST);
	StackInit(&ps->popST);
	return ps;
}

void cQueueAppendTail(CQueue* obj, int value) {
	//���ݴ浽���ջ
	StackPush(&obj->pushST, value);
}

int cQueueDeleteHead(CQueue* obj) {
	if (StackEmpty(&obj->popST))
	{//�������ջΪ�գ������ջ�����ݵ���ȥ
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	//��ȡ����ջ��ջ��Ԫ��
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