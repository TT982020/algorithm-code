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