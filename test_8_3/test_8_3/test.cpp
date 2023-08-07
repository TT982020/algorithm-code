#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//再简单的操作，也要调用函数进行，因为函数里面会进行一些检测
int main() {
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);
	SLPushBack(&s, 8);

	SLPrint(&s);

	SLPopBack(&s);
	SLPrint(&s);

	int pos = SLFind(&s, 6);
	if (pos != -1)
	{
		SLInsert(&s, pos, 100);
	}
	
	SLPrint(&s);
	SLDestroy(&s);

	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 10;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data = 20;

	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data = 30;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	PrintList(node1);

}