#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

void CheckCapacity(SL* ps);

void SLPushBack(SL* ps, SLDataType data);

void SLPopBack(SL* ps);

void SLPushFront(SL* ps, SLDataType data);

void SLPopFront(SL* ps);

//在pos位置前插入data
void SLInsert(SL* ps, int pos, SLDataType data);

//删除pos位置的值
void SLErase(SL* ps, int pos);

int SLFind(SL* ps, SLDataType data);