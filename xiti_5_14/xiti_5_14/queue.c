#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
// 初始化队列 
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	node->_next = NULL;
	node->_data = data;
	if (q->_rear == NULL)
	{
		q->_rear = q->_front = node;
	}
	else {
		q->_rear->_next = node;
		q->_rear = q->_rear->_next;
	}
}
// 队头出队列 
void QueuePop(Queue* q) {
	assert(q);
	assert(q->_front);
	//如果不判断只有一个节点的情况，会导致_rear指针为野指针
	if (q->_front->_next == NULL)
	{
		QNode* del = q->_front;
		q->_front = q->_rear = NULL;
		free(del);
	}
	else {
		QNode* del = q->_front;
		q->_front = q->_front->_next;
		free(del);
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q) {
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q) {
	assert(q);
	QNode* cur = q->_front;
	int sz = 0;
	while (cur != NULL)
	{
		sz++;
		cur = cur->_next;
	}
	return sz;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->_front == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q) {
	assert(q);
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}