#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

void STInit(ST* ps) {
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = -1;
}

void STDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = -1;
}

void STPush(ST* ps, STDataType x) {
	assert(ps);
	int cap = 0;
	if (ps->capacity == ps->top + 1)
	{
		//À©ÈÝ
		cap = ps->top == -1 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * cap);
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(1);
		}
		ps->a = tmp;
		ps->capacity = cap;
	}
	ps->a[++ps->top] = x;
}

void STPop(ST* ps) {
	assert(ps);
	assert(ps->top > -1);
	ps->top--;
}

STDataType STTop(ST* ps) {
	assert(ps);
	assert(ps->top > -1);
	return ps->a[ps->top];
}

int STSize(ST* ps) {
	assert(ps);
	return ps->top + 1;
}

bool STEmpty(ST* ps) {
	assert(ps);
	return  ps->top == -1;
}
