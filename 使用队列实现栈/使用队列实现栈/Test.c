#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int QDataType;
//链表结构：表示队列
typedef struct QListNode
{
	QDataType data;//数据
	struct QListNode* next;//指向下一个的指针
}QNode;
//队列机构
typedef struct Queue
{
	QNode* head;//队头
	QNode* tail;//队尾
}Queue;
//初始化
void QueueInit(Queue* pq);
//销毁队列
void QueueDestroy(Queue* pq);
//队尾入队
void QueuePush(Queue* pq, QDataType x);
//队头出队
void QueuePop(Queue* pq);
//获取队头数据
QDataType QueueFront(Queue* pq);
//获取队尾数据
QDataType QueueBack(Queue* pq);
//获取队列有效数据个数
int QueueSize(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;//保存cur下一个节点
		free(cur);//释放
		cur = next;//cur指向它的下一个节点
	}
	//所有节点释放后，将头尾指针置为空指针
	pq->head = pq->tail = NULL;
}
//队尾入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//开辟空间
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
		pq->head = pq->tail = newnode;//如果没有节点，直接链接
	else
	{
		pq->tail->next = newnode;//有节点，尾节点next链接
		pq->tail = newnode;//然后尾指针指向newnode
	}
}
//队头出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{//一个节点的情况
		free(pq->head);//头尾指向同一个空间，直接释放
		pq->head = pq->tail = NULL;//
	}
	else
	{//多个节点的情况
		QNode* next = pq->head->next;//保存头节点的下一个节点
		free(pq->head);//释放
		pq->head = next;//头节点指向下一个节点
	}
}
//获取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//获取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//获取队列有效数据个数
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

typedef struct {
	Queue q1;//队列2
	Queue q2;//队列2
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate() {
	MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
	if (ps == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	//初始化
	QueueInit(&ps->q1);
	QueueInit(&ps->q2);

	return ps;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//1.把数据往不为空的队列入数据
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{//如果队列1有数据，空队列emptyQ指向队列2
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	//2.倒数据
	while (QueueSize(nonemptyQ)>1)
	{//将有数据的队列倒到空队列
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}
	int top = QueueFront(nonemptyQ);//保存出队头数据
	QueuePop(nonemptyQ);//出队列
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	//返回不为空的队列队尾数据
	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
	//当两个队列都为空时，队列才为空
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	//创建的栈中还有q1和q2两个队列，所以要先释放两个队列，在释放栈
	free(obj);
}
int main()
{
	return 0;
}