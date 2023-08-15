#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList01() {
	LTNode* phead = NULL;
	phead = LTInit(phead);
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPushBack(phead, 6);
	LTPrint(phead);

	LTPopBack(phead);
	LTPopBack(phead);

	LTPrint(phead);

	LTPushFront(phead, 100);

	LTPrint(phead);

	LTPopFront(phead);
	LTPopFront(phead);

	LTPrint(phead);
}

void TestList02() {
	LTNode* phead = NULL;
	phead = LTInit(phead);
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPushBack(phead, 6);
	LTPrint(phead);

	LTPopBack(phead);
	LTPopBack(phead);

	LTPrint(phead);

	LTPushFront(phead, 100);

	LTPrint(phead);

	LTPopFront(phead);
	LTPopFront(phead);

	LTPrint(phead);

	LTNode* pos = LTFind(phead, 3);
	LTInsert(pos, 1000);
	LTPrint(phead);

	LTErase(pos);
	LTPrint(phead);
}

void TestList03() {
	LTNode* phead = NULL;
	phead = LTInit(phead);
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPushBack(phead, 6);
	LTPrint(phead);

	LTPushFront(phead, 10);
	LTPushFront(phead, 20);
	LTPushFront(phead, 30);
	LTPushFront(phead, 40);
	LTPushFront(phead, 50);
	LTPrint(phead);

	LTDestroy(phead);
	phead = NULL;
}

int main() {
	//TestList01();
	//TestList02();
	TestList03();
	return 0;
}