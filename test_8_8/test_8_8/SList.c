#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SLTPrint(SLTNode* phead){
	 SLTNode* cur = phead;
	 while (cur)
	 {
		 printf("%d->", cur->data);
		 cur = cur->next;
	 }
	 printf("NULL\n");
}

SLTNode* BuyListNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode =  BuyListNode(x);
	if (*pphead == NULL)
	{
		//改变结构体指针，需要使用二级指针
		*pphead = newnode;
	}

	//以下形式不行，因为phead是形参，要修改 SLTNode* 类型，需要传入 SLTNode**
	/*if (phead == NULL)
	{
		phead = newnode;
	}*/

	else {
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		//改变结构体，需要用结构体指针
		tail->next = newnode;
	}
}


void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode =  BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLTNode** pphead) {
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* curPrev = NULL;
		SLTNode* cur = *pphead;
		while (cur->next)
		{
			curPrev = cur;
			cur = cur->next;
		}
		free(cur);
		curPrev->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead) {
	//空
	assert(*pphead);

	//非空
	SLTNode* newhead = (*pphead)->next;
	free(*pphead);
	*pphead = newhead;
}


SLTNode* SLTFind(SLTNode* phead, SLTDataType x) {
	SLTNode* cur = phead;
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

//在pos之前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pos);
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SLTNode* newnode = BuyListNode(x);
		newnode->next = pos;
		cur->next = newnode;
	}

}

//在pos之后插入
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}


//删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}

//删除pos之后的
void SLTEraseAfter(SLTNode* pos) {
	assert(pos);
	assert(pos->next);
	SLTNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
}