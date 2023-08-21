#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
int main() {
	ListNode* phead = ListCreate();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);

	ListPushFront(phead, 10);
	ListPushFront(phead, 20);
	ListPushFront(phead, 30);
	ListPushFront(phead, 40);
	ListPrint(phead);

	ListPopBack(phead);
	ListPrint(phead);

	ListPopFront(phead);
	ListPrint(phead);

	ListNode* pos = ListFind(phead, 3);
	ListInsert(pos, 1000);
	ListPrint(phead);

	ListErase(pos);
	ListPrint(phead);

	ListDestory(phead);
}