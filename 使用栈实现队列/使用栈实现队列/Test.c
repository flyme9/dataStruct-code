#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
/* ����һ��ջ��
 * ջָ�롢ջ�Ĵ�С��ջ���������
 */
typedef int STDataType;
typedef struct Stack {
	STDataType* stk;
	int stkSize;
	int stkCapcaity;
}T_Stack, *PT_Stack;

/* ջ�ĳ�ʼ�� */
PT_Stack stackCreate(int capacity) {
	PT_Stack ret = (PT_Stack)malloc(sizeof(T_Stack));
	ret->stk = (STDataType*)malloc(sizeof(STDataType) * capacity);
	ret->stkSize = 0;
	ret->stkCapcaity = capacity;
	return ret;
}

/* ��ջ���� */
void stackPush(PT_Stack obj, int x) {
	obj->stk[obj->stkSize++] = x;
}

/* ��ջ���� */
void stackPop(PT_Stack obj) {
	obj->stkSize--;
}

/* ���ջ��Ԫ�� */
int satckTop(PT_Stack obj) {
	return obj->stk[obj->stkSize - 1];
}

/* �ж�ջ�Ƿ�Ϊ�� */
int stackEmpty(PT_Stack obj) {
	return obj->stkSize == 0;
}

/* �ͷ�ջ���ڴ�ռ� */
void satckFree(PT_Stack obj) {
	free(obj->stk);
}

/* ������У�ʹ������ջ */
typedef struct MyQueue {
	PT_Stack inStack;
	PT_Stack outSatck;
}MyQueue, *PT_MyQueue;

/** Initialize your data structure here. */

PT_MyQueue myQueueCreate() {
	PT_MyQueue ret = (PT_MyQueue)malloc(sizeof(MyQueue));
	ret->inStack = stackCreate(100);
	ret->outSatck = stackCreate(100);
	return ret;
}

/* ��ջ���ջ��ֵ */
void in2out(MyQueue* obj) {
	while (!stackEmpty(obj->inStack)) {
		stackPush(obj->outSatck, satckTop(obj->inStack));
		stackPop(obj->inStack);
	}
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stackPush(obj->inStack, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (stackEmpty(obj->outSatck)) {
		in2out(obj);
	}
	int x = satckTop(obj->outSatck);
	stackPop(obj->outSatck);
	return x;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (stackEmpty(obj->outSatck)) {
		in2out(obj);
	}
	return satckTop(obj->outSatck);
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
	return stackEmpty(obj->inStack) && stackEmpty(obj->outSatck);
}

void myQueueFree(MyQueue* obj) {
	satckFree(obj->inStack);
	satckFree(obj->outSatck);
}
int main()
{
	MyQueue* q1 = (MyQueue*)malloc(sizeof(MyQueue));
	q1 = myQueueCreate();
	myQueuePush(q1, 1);
	myQueuePush(q1, 2);
	myQueuePeek(q1);
	myQueuePop(q1);
	myQueueEmpty(q1);
	return 0;
}