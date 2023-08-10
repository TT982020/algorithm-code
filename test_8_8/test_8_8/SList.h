#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);

SLTNode* BuyListNode(SLTDataType x);

void SLTPushBack(SLTNode** phead, SLTDataType x);