#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int QDataType;
//����ṹ����ʾ����
typedef struct QListNode
{
	QDataType data;//����
	struct QListNode* next;//ָ����һ����ָ��
}QNode;
//���л���
typedef struct Queue
{
	QNode* head;//��ͷ
	QNode* tail;//��β
}Queue;
//��ʼ��
void QueueInit(Queue* pq);
//���ٶ���
void QueueDestroy(Queue* pq);
//��β���
void QueuePush(Queue* pq, QDataType x);
//��ͷ����
void QueuePop(Queue* pq);
//��ȡ��ͷ����
QDataType QueueFront(Queue* pq);
//��ȡ��β����
QDataType QueueBack(Queue* pq);
//��ȡ������Ч���ݸ���
int QueueSize(Queue* pq);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;//����cur��һ���ڵ�
		free(cur);//�ͷ�
		cur = next;//curָ��������һ���ڵ�
	}
	//���нڵ��ͷź󣬽�ͷβָ����Ϊ��ָ��
	pq->head = pq->tail = NULL;
}
//��β���
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//���ٿռ�
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
		pq->head = pq->tail = newnode;//���û�нڵ㣬ֱ������
	else
	{
		pq->tail->next = newnode;//�нڵ㣬β�ڵ�next����
		pq->tail = newnode;//Ȼ��βָ��ָ��newnode
	}
}
//��ͷ����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{//һ���ڵ�����
		free(pq->head);//ͷβָ��ͬһ���ռ䣬ֱ���ͷ�
		pq->head = pq->tail = NULL;//
	}
	else
	{//����ڵ�����
		QNode* next = pq->head->next;//����ͷ�ڵ����һ���ڵ�
		free(pq->head);//�ͷ�
		pq->head = next;//ͷ�ڵ�ָ����һ���ڵ�
	}
}
//��ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//��ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//��ȡ������Ч���ݸ���
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
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

typedef struct {
	Queue q1;//����2
	Queue q2;//����2
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate() {
	MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
	if (ps == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	//��ʼ��
	QueueInit(&ps->q1);
	QueueInit(&ps->q2);

	return ps;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//1.����������Ϊ�յĶ���������
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
	{//�������1�����ݣ��ն���emptyQָ�����2
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	//2.������
	while (QueueSize(nonemptyQ)>1)
	{//�������ݵĶ��е����ն���
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}
	int top = QueueFront(nonemptyQ);//�������ͷ����
	QueuePop(nonemptyQ);//������
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	//���ز�Ϊ�յĶ��ж�β����
	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
	//���������ж�Ϊ��ʱ�����в�Ϊ��
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	//������ջ�л���q1��q2�������У�����Ҫ���ͷ��������У����ͷ�ջ
	free(obj);
}
int main()
{
	return 0;
}