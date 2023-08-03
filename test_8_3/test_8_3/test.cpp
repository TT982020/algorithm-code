#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

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
	SLDestroy(&s);


}