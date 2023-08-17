#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

int main() {
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);

	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}

	STDestroy(&st);

}