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
		//�ı�ṹ��ָ�룬��Ҫʹ�ö���ָ��
		*pphead = newnode;
	}

	//������ʽ���У���Ϊphead���βΣ�Ҫ�޸� SLTNode* ���ͣ���Ҫ���� SLTNode**
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
		//�ı�ṹ�壬��Ҫ�ýṹ��ָ��
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
	//��
	assert(*pphead);

	//�ǿ�
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

//��pos֮ǰ����
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

//��pos֮�����
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}


//ɾ��posλ��
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

//ɾ��pos֮���
void SLTEraseAfter(SLTNode* pos) {
	assert(pos);
	assert(pos->next);
	SLTNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
}