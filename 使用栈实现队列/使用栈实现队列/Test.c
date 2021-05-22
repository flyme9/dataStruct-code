#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
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
	assert(!StackEmpty(ps));//ջ���ˣ����ñ�����ֹ����
	ps->top--;
}
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//ջ���ˣ����ñ�����ֹ����
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

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	//������ʼ������
	MyQueue* ps = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&ps->pushST);
	StackInit(&ps->popST);
	return ps;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	//���ݴ浽���ջ
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
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

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{//�������ջΪ�գ������ջ�����ݵ���ȥ
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	//���س���ջ��ջ��Ԫ��
	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	//������ջ��Ϊ��ʱ������true������false
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);

}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);

}
int main()
{
	MyQueue* q = myQueueCreate();
	myQueuePush(q, 1);
	myQueuePush(q, 2);
	printf("%d ", myQueuePeek(q));
	printf("%d ", myQueuePop(q));
	printf("%d ", myQueuePop(q));
	printf("%d ",myQueueEmpty(q));
	return 0;
}