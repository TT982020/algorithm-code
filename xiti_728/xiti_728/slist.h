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

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SListDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestroy(SListNode** pphead);

//在pos位置之前插入
void SListInsert(SListNode** pphead, SListNode* pos, SListDataType x);


//在pos位置进行删除
void SListErase(SListNode** phead, SListNode* pos);