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
* ��һ�ַ�������phead�ڵ���������д������ڵ�ĸ����������ܳ��ȣ�
* ���������������һ�����⣬���������������int�ͣ���ô�泤�ȿ��ܻ���һЩ����
*/
int LTSize(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);

void LTInsert(LTNode* pos, LTDataType x);

void LTErase(LTNode* pos);

void LTDestroy(LTNode* phead);
