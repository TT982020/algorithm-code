#include "heap.h"
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n) {
	assert(hp);

	HPDataType* p = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (p == NULL)
	{
		exit(1);
	}
	hp->_a = p;
	hp->_capacity = n;
	hp->_size = n;
	for (int i = 0; i < n; i++) {
		hp->_a[i] = a[i];
	}
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
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

void AdjustDown(HPDataType* a, int n, int parent) {
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

// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	if (hp->_capacity == hp->_size)
	{
		int cap = hp->_size == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, cap * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(1);
		}
		hp->_a = tmp;
		hp->_capacity = cap;
	}
	hp->_a[hp->_size++] = x;
	AdjustUp(hp->_a, hp->_size - 1);
}
// 堆的删除
void HeapPop(Heap* hp) {
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp) {
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp) {
	return hp->_size == 0;
}

void HeapSort(int* a, int n) {
	//建小堆,降序
	for (int i = (n - 2) / 2; i >= 0; i--) {
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