#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QueueDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataType data;
}QNode;

typedef struct Queue {
	struct QueueNode* head;
	struct QueueNode* tail;
	int size;
}Que;

void QueueInit(Que* pq);

void QueueDestroy(Que* pq);

void QueuePush(Que* pq, QueueDataType data);

void QueuePop(Que* pq);

QueueDataType QueueFront(Que* pq);

QueueDataType QueueBack(Que* pq);

bool QueueEmpty(Que* pq);

int QueueSize(Que* pq);


