#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SLInit(SL* ps) {
	ps->list = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->list == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}


void SLDestroy(SL* ps) {
	free(ps->list);
	ps->size = 0;
	ps->capacity = 0;
	ps->list = NULL;
}
void CheckCapacity(SL* ps) {
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->list, sizeof(SLDataType) * 2 * ps->capacity);
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		ps->list = tmp;
		ps->capacity *= 2;
	}
}

void SLPushBack(SL* ps, SLDataType data) {
	CheckCapacity(ps);
	ps->list[ps->size++] = data;
}

void SLPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->list[i]);
	}
	printf("\n");
}

void SLPopBack(SL* ps){
	assert(ps->size > 0);
	ps->size--;
}

void SLPushFront(SL* ps, SLDataType data) {
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->list[end + 1] = ps->list[end];
		end--;
	}
	ps->list[0] = data;
	ps->size++;
}

void SLPopFront(SL* ps) {
	assert(ps->size > 0);
	int start = 0;
	while (start <= ps->size - 2)
	{
		ps->list[start] = ps->list[start + 1];
		start++;
	}
	ps->size--;
}

//在pos位置前插入data
void SLInsert(SL* ps, int pos, SLDataType data) {
	assert(pos >= 0 && pos <= ps->size);
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->list[end + 1] = ps->list[end];
		--end;
	}
	ps->list[pos] = data;
	ps->size++;
}

//删除pos位置的值
void SLErase(SL* ps, int pos) {
	assert(pos >= 0 && pos < ps->size);
	int begin = pos;
	while (pos < ps->size - 1)
	{
		ps->list[begin] = ps->list[begin + 1];
		begin++;
	}
	ps->size--;
}

int SLFind(SL* ps, SLDataType data) {
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->list[i] == data)
		{
			return i;
		}
	}
	return -1;
}