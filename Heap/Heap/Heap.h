#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);

void HPDestroy(HP* php);

void HPPush(HP* php, HPDataType x);

void HPPop(HP* php);

HPDataType HPTOP(HP* php);

bool HPEmpty(HP* php);

int HPSize(HP* php);

void AdjustUp(HPDataType* a, int child);

void AdjustDown(int* a, int n, int parent);

void HeapSort1(int* a, int n);

void HeapSort2(int* a, int n);