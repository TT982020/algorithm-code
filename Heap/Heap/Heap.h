#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);

void HPDestroy(HP* php);

void HPPush(HP* php, HPDataType x);

