#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"
void testStack() {
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

void testQueue() {
	Que q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestroy(&q);
}
int main() {
	//testStack();
	testQueue();
}