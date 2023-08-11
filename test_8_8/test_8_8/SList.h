#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//Printû��Ҫ�ı��������Բ��ô�����ָ��
void SLTPrint(SLTNode* phead);

SLTNode* BuyListNode(SLTDataType x);

void SLTPushBack(SLTNode** pphead, SLTDataType x);

void SLTPushFront(SLTNode** pphead, SLTDataType x);


void SLTPopBack(SLTNode** pphead);

void SLTPopFront(SLTNode** pphead);

SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

//��pos֮ǰ����
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//��pos֮�����
void SLTInsertAfter(SLTNode* pos, SLTDataType x);


//ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos);

//ɾ��pos֮���
void SLTEraseAfter(SLTNode* pos);