#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"
SListNode* BuyListNode(SListDataType x) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* phead) {
	assert(phead);
	while (phead)
	{
		printf("%d ", phead->data);
	
		phead = phead->next;
	}
	printf("\n");
}

void SListPushBack(SListNode** pphead, SListDataType x) {
	assert(pphead);
	SListNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* cur = *pphead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SListPushFront(SListNode** pphead, SListDataType x) {
	assert(pphead);
	SListNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SListNode** pphead) {
	assert(pphead);
	assert(*pphead);
	//如果只有一个节点，需要修改*phead
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* cur = *pphead, * prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		free(cur);
	}
}

void SListPopFront(SListNode** pphead) {
	assert(pphead);
	assert(*pphead);
	SListNode* cur = *pphead;
	SListNode* next = (*pphead)->next;
	
	free(cur);
	*pphead = next;
}

SListNode* SListFind(SListNode* phead, SListDataType x) {
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
//pos位置插入数据需要找到pos位置的前一个节点，在pos位置之后插入，那么pos就是前一个节点
void SListInsertAfter(SListNode* pos, SListDataType x) {
	assert(pos);
	SListNode* newnode = (SListNode*)BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
//删除数据需要找到删除位置的前一个节点，入股删除pos之后的值，那么pos就是前一个节点
void SListEraseAfter(SListNode* pos) {
	assert(pos);
	assert(pos->next);
	SListNode* del = pos->next;
	pos->next = del->next;
	free(del);
}
// 单链表的销毁
void SListDestroy(SListNode** pphead) {
	assert(pphead);
	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

//在pos位置之前插入
void SListInsert(SListNode** pphead, SListNode* pos, SListDataType x) {
	assert(pphead);
	assert(pos);
	if ((*pphead) == pos)
	{
		SListPushFront(pphead, x);
	}
	else {
		SListNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SListNode* newnode = (SListNode*)BuyListNode(x);
		newnode->next = cur->next;
		cur->next = newnode;
	}
}


//在pos位置进行删除
void SListErase(SListNode** pphead, SListNode* pos) {
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else {
		SListNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}