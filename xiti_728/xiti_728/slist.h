#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;

typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;
}SListNode;


SListNode* BuyListNode(SListDataType x);


void SListPrint(SListNode* phead);

void SListPushBack(SListNode** pphead, SListDataType x);

void SListPushFront(SListNode** pphead, SListDataType x);

void SListPopBack(SListNode** pphead);

void SListPopFront(SListNode** pphead);

SListNode* SListFind(SListNode* phead, SListDataType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SListDataType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestroy(SListNode** pphead);

//��posλ��֮ǰ����
void SListInsert(SListNode** pphead, SListNode* pos, SListDataType x);


//��posλ�ý���ɾ��
void SListErase(SListNode** phead, SListNode* pos);