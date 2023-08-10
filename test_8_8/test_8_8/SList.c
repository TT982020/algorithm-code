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

	//������ʽ���У���Ϊphead���βΣ�Ҫ�޸� SLTNode* ���ͣ���Ҫ���� SLTNode**
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

