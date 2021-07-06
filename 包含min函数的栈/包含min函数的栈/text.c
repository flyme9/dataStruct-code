#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10001

typedef struct {
	int* data;
	int top;
	int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
	obj->data = (int*)malloc(sizeof(int) * MAX_SIZE);
	obj->top = -1;
	obj->min = INT_MAX;
	return obj;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top >= MAX_SIZE) {
		return;
	}
	obj->data[++(obj->top)] = x;
	if (x < obj->min) {
		obj->min = x;
	}
}

void minStackPop(MinStack* obj) {
	if (obj->top < 0) {
		return;
	}
	obj->top--;
	if (obj->top >= 0) {
		obj->min = obj->data[obj->top];
	}
	else {
		obj->min = INT_MAX;
	}
	for (int i = obj->top; i >= 0; i--) {
		if (obj->data[i] < obj->min) {
			obj->min = obj->data[i];
		}
	}
}

int minStackTop(MinStack* obj) {
	return obj->data[obj->top];
}

int minStackMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj);
}
int main()
{
	return 0;
}