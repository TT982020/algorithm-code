#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps) {
	assert(ps);
	SLDateType* plist = (SLDateType* )malloc(sizeof(SLDateType) * 4);
	if (plist == NULL)
	{
		perror("init error");
		exit(1);
	}
	ps->a = plist;
	ps->capacity = 4;
	ps->size = 0;
}
void SeqListDestroy(SeqList* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = 0;
	ps->size = 0;
	ps->a = NULL;
}

void checkCapacity(SeqList* ps) {
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLDateType* plist = (SLDateType*)realloc(ps->a, 2 * ps->capacity *sizeof(SLDateType));
		if (plist == NULL)
		{
			perror("check capacity failed");
			exit(1);
		}
		ps->a = plist;
		ps->capacity *= 2;
	}
}

void SeqListPrint(SeqList* ps) {
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x) {
	assert(ps);
	checkCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x) {
	assert(ps);
	checkCapacity(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps) {
	assert(ps);
	if (ps->size == 0)
	{
		perror("顺序表中没有元素，无法删除");
		exit(1);
	}
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps) {
	assert(ps);
	if (ps->size == 0)
	{
		perror("顺序表中没有元素，无法删除");
		exit(1);
	}
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x) {
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x) {
			return i;
		}
	}
	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	checkCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size - 1);
	if (ps->size == 0)
	{
		perror("顺序表中没有元素，无法删除");
		exit(1);
	}
	for (int i = pos; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}