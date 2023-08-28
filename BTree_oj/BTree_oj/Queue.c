#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Que* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueueDestroy(Que* pq) {
	QNode* tmp = pq->head;
	while (tmp)
	{
		QNode* next = tmp->next;
		free(tmp);
		tmp = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Que* pq, QueueDataType data) {
	assert(pq);
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if (tmp == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	tmp->data = data;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = tmp;
		tmp->next = NULL;
		pq->size++;
	}
	else {
		pq->tail->next = tmp;
		pq->tail = tmp;
		pq->tail->next = NULL;
		pq->size++;
	}
}

void QueuePop(Que* pq) {
	assert(pq);
	assert(pq->size > 0);
	if (pq->size == 1)
	{
		QNode* tmp = pq->head;
		pq->head = pq->tail = NULL;
		pq->size--;
		free(tmp);
	}
	else {
		QNode* tmp = pq->head;
		pq->head = pq->head->next;
		free(tmp);
		pq->size--;
	}
}

QueueDataType QueueFront(Que* pq) {
	assert(pq);
	assert(pq->size > 0);
	return pq->head->data;
}

QueueDataType QueueBack(Que* pq) {
	assert(pq);
	assert(pq->size > 0);
	return pq->tail->data;
}



bool QueueEmpty(Que* pq) {
	assert(pq);
	return pq->head == NULL;
}

int QueueSize(Que* pq) {
	assert(pq);
	return pq->size;
}


