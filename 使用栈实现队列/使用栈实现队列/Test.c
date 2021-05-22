#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
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
	assert(!StackEmpty(ps));//栈空了，调用报错，终止程序
	ps->top--;
}
//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//栈空了，调用报错，终止程序
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

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	//创建初始化队列
	MyQueue* ps = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&ps->pushST);
	StackInit(&ps->popST);
	return ps;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	//数据存到入队栈
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
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

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{//如果出队栈为空，则将入队栈的数据倒进去
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	//返回出队栈的栈顶元素
	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	//当两个栈都为空时，返回true，否则false
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