#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void HPInit(HP* php) {
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HPDestroy(HP* php) {
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void Swap(HPDataType* p1, HPDataType* p2) {
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child) {
	int parent = (child - 1) / 2;
	//while(parent>0) //不行
	while (child > 0)
	{
		if (a[parent] > a[child]) {
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void AdjustDown(int* a, int n, int parent) {
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}

		if (a[parent] > a[child]) {
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x) {
	assert(php);
	if (php->size == php->capacity)
	{
		int cap = php->size == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, cap * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(1);
		}
		php->a = tmp;
		php->capacity = cap;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}

void HPPop(HP* php) {
	assert(php);
	assert(!HPEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

HPDataType HPTOP(HP* php) {
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

bool HPEmpty(HP* php) {
	assert(php);
	return php->size == 0;
}

int HPSize(HP* php) {
	assert(php);
	return php->size;
}

//弊端：1.先需要一个堆
//      2.空间复杂度比较高  
//      3.时间复杂度 NlogN
void HeapSort1(int* a, int n) {
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < n; i++)
	{
		HPPush(&hp, a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = HPTOP(&hp);
		HPPop(&hp);
	}
	HPDestroy(&hp);
}

void HeapSort2(int* a, int n) {
	//升序：建大堆
	//降序：建小堆

	//建堆：向上调整建堆
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	//向下调整建堆
	//叶子节点不需要调整，倒数第一个非叶子节点，最后一个节点的父亲开始调整
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}