#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Stack.h"

void PrintArray(int* a, int n);

void InsertSort(int* a, int n);

void InsertSort1(int* a, int n);

void ShellSort(int* a, int n);

void BubbleSort(int* a, int n);

void SelectSort(int* a, int n);

void HeapSort(int* a, int n);

void QuickSort(int* a, int begin, int end);

void QuickSortNonR(int* a, int begin, int end);

void QuickSortThreePath(int* a, int begin, int end);

void MergeSort(int* a, int n);

void MergeSortNonR(int* a, int n);

void MergeSortNonR2(int* a, int n);

void CountSort(int* a, int n);