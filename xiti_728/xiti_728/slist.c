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
	//���ֻ��һ���ڵ㣬��Ҫ�޸�*phead
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
//posλ�ò���������Ҫ�ҵ�posλ�õ�ǰһ���ڵ㣬��posλ��֮����룬��ôpos����ǰһ���ڵ�
void SListInsertAfter(SListNode* pos, SListDataType x) {
	assert(pos);
	SListNode* newnode = (SListNode*)BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
//ɾ��������Ҫ�ҵ�ɾ��λ�õ�ǰһ���ڵ㣬���ɾ��pos֮���ֵ����ôpos����ǰһ���ڵ�
void SListEraseAfter(SListNode* pos) {
	assert(pos);
	assert(pos->next);
	SListNode* del = pos->next;
	pos->next = del->next;
	free(del);
}
// �����������
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

//��posλ��֮ǰ����
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


//��posλ�ý���ɾ��
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