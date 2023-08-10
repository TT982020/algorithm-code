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


void SLTPushBack(SLTNode** phead, SLTDataType x) {
	SLTNode* newnode =  BuyListNode(x);
	if (*phead == NULL)
	{
		*phead = newnode;
	}

	//以下形式不行，因为phead是形参，要修改 SLTNode* 类型，需要传入 SLTNode**
	/*if (phead == NULL)
	{
		phead = newnode;
	}*/

	else {
		SLTNode* tail = *phead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

