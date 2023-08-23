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
	free(php);
}

void AdjustDown(HP* php, int child) {
	int parent = (child - 1) / 2;
	//while(parent>0) //²»ÐÐ
	while (child > 0)
	{
		if (php->a[parent] > php->a[child]) {
			HPDataType tmp = php->a[child];
			php->a[child] = php->a[parent];
			php->a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
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
	AdjustDown(php, php->size - 1);
}