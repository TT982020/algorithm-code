#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* LTInit(LTNode* phead);

void LTPrint(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType data);

void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType data);

void LTPopFront(LTNode* phead);

/*
* 有一种方法是在phead节点的数据域中存放链表节点的个数（链表总长度）
* 但是这个方法存在一个问题，就是如果数据域不是int型，那么存长度可能会有一些问题
*/
int LTSize(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);

void LTInsert(LTNode* pos, LTDataType x);

void LTErase(LTNode* pos);

void LTDestroy(LTNode* phead);
