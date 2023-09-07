#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"
#include <time.h>
void TestInsertSort() {
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	int n = sizeof(a) / sizeof(int);
	InsertSort1(a, n);
	PrintArray(a, n);

}

void TestSelectSort() {
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	int n = sizeof(a) / sizeof(int);
	SelectSort(a, n);
	PrintArray(a, n);

}

void TestHeapSort() {
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	int n = sizeof(a) / sizeof(int);
	HeapSort(a, n);
	PrintArray(a, n);

}

void TestQuickSort() {
	int a[] = { 4,7,1,9,3,6,5,8,3,2,0 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, n - 1);
	PrintArray(a, n);

}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//BubbleSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//SelectSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	HeapSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("BubbleSort:%d\n", end3 - begin3);
	printf("SelectSort:%d\n", end4 - begin4);
	printf("HeapSort:%d\n", end5 - begin5);
	printf("QuickSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
void TestShellSort() {
	int a[] = { 9,8,7,6,5,4,3,3,2,1,0 };
	int n = sizeof(a) / sizeof(int);
	ShellSort(a, n);
	PrintArray(a, n);
}
int main() {
	//TestInsertSort();
	//TestShellSort();
	TestOP();
	//TestSelectSort();
	//TestHeapSort();
	//TestQuickSort();
}