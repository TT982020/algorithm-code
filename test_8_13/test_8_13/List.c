#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

LTNode* BuyLTNode(LTDataType x) {
	LTNode* newhead = (LTNode*)malloc(sizeof(LTNode));
	if (newhead == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	newhead->data = x;
	
	return newhead;
}

LTNode* LTInit(LTNode* phead) {
	phead = BuyLTNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void LTPushBack(LTNode* phead, LTDataType data) {
	assert(phead);
	LTNode* tail = phead->prev;
	
	LTNode* newnode = BuyLTNode(data);

	newnode->prev = tail;
	tail->next = newnode;
	
	newnode->next = phead;
	phead->prev = newnode;

	//LTInsert(phead, data);
}

void LTPrint(LTNode* phead) {
	assert(phead);
	printf("phead->");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void LTPopBack(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);

	LTNode* del = phead->prev;

	LTNode* tail = del->prev;

	tail->next = phead;
	phead->prev = tail;

	free(del);

	//LTErase(phead->prev);
}

void LTPushFront(LTNode* phead, LTDataType data) {
	assert(phead);
	LTNode*  newnode = BuyLTNode(data);
	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;

	//LTInsert(phead->next, data);
}

void LTPopFront(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);

	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;

	free(del);

	//LTErase(phead->next);
}

int LTSize(LTNode* phead) {
	assert(phead);
	int size = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

LTNode* LTFind(LTNode* phead, LTDataType x) {
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x) {
	assert(pos);
	LTNode* newnode = BuyLTNode(x);
	
	LTNode* posPrev = pos->prev;

	newnode->prev = posPrev;
	posPrev->next = newnode;

	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos) {
	assert(pos);

	LTNode* posPrev = pos->prev;
	posPrev->next = pos->next;
	pos->next->prev = posPrev;

	free(pos);
}

void LTDestroy(LTNode* phead) {
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}