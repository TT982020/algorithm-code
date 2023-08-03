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

void SLPushBack(SL* ps, SLDataType data) {
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
	ps->size--;
}