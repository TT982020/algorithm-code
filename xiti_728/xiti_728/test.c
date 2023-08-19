#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"
int main() {
	SListNode* node = NULL;
	SListPushBack(&node, 1);
	SListPushBack(&node, 2);
	SListPushBack(&node, 3);
	SListPushBack(&node, 4);

	SListPrint(node);

	SListPushFront(&node, 100);
	SListPushFront(&node, 200);
	SListPushFront(&node, 300);
	SListPushFront(&node, 400);

	SListPrint(node);

	SListPopBack(&node);
	SListPopFront(&node);

	SListPrint(node);

	SListNode* pos = SListFind(node, 300);
	if (pos)
	{
		SListInsertAfter(pos, 10000);
		SListPrint(node);
	}

	SListEraseAfter(pos);
	SListPrint(node);

	SListInsert(&node, pos, 5000);
	SListPrint(node);

	SListErase(&node, pos);
	SListPrint(node);
}