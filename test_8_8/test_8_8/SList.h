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

//Print没有要改变链表，所以不用传二级指针
void SLTPrint(SLTNode* phead);

SLTNode* BuyListNode(SLTDataType x);

void SLTPushBack(SLTNode** pphead, SLTDataType x);

void SLTPushFront(SLTNode** pphead, SLTDataType x);


void SLTPopBack(SLTNode** pphead);

void SLTPopFront(SLTNode** pphead);

SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

//在pos之前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//在pos之后插入
void SLTInsertAfter(SLTNode* pos, SLTDataType x);


//删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos);

//删除pos之后的
void SLTEraseAfter(SLTNode* pos);