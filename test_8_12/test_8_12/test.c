#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

int main() {
	SeqList s;
	SeqListInit(&s);


	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	int pos = SeqListFind(&s, 6);
	if (pos != -1)
	{
		SeqListInsert(&s, pos, 100);
	}

	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 10000);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	pos = SeqListFind(&s, 0);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}

	SeqListPrint(&s);
	SeqListDestroy(&s);

}