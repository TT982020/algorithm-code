#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef int SLDataType;
//typedef struct SeqList {
//	SLDataType arr[N];
//	int size;
//}SeqList;

typedef struct SeqList {
	SLDataType* list;
	int size;
	int capacity;
}SL;

void SLInit(SL* ps);
void SLDestroy(SL* ps);

void SLPrint(SL* ps);

void SLPushBack(SL* ps, SLDataType data);

void SLPopBack(SL* ps);
