#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
// ��ʼ������ 
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_rear = NULL;
}
// ��β����� 
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
// ��ͷ������ 
void QueuePop(Queue* q) {
	assert(q);
	assert(q->_front);
	//������ж�ֻ��һ���ڵ��������ᵼ��_rearָ��ΪҰָ��
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->_front == NULL;
}
// ���ٶ��� 
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