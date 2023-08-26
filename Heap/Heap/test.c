#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
//int main() {
//	HP hp;
//	HPInit(&hp);
//	int a[] = {32,50,60,100,65,70};
//	for (int i = 0; i < 6; i++) {
//		HPPush(&hp, a[i]);
//	}
//	for (int i = 0; i < 6; i++) {
//		printf("%d ", hp.a[i]);
//	}
//	printf("\n");
//
//	while (!HPEmpty(&hp))
//	{
//		printf("%d ", HPTOP(&hp));
//		HPPop(&hp);
//	}
//	printf("\n");
//	for (int i = 0; i < 6; i++) {
//		printf("%d ", hp.a[i]);
//	}
//}

//int main() {
//	//topk 问题
//	//10000个，找出最大的前10个
//	//建堆，然后pop 9次
//}

//int main() {
//	int a[] = { 100,2,3,89,5,4,66 };
//	int n = sizeof(a) / sizeof(int);
//	/*HeapSort1(a, n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}*/
//	HeapSort2(a, n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}

//topK 问题

void createData() {
	srand((unsigned int)time(0));
	int n = 1000;
	FILE* fout = fopen("test.txt", "w");
	if (fout == NULL)
	{
		perror("file open failed");
		exit(-1);
	}
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 1000000;
		fprintf(fout, "%d\n", x);
	}
	fclose(fout);
}

void PrintTopK(int k) {
	FILE* fin = fopen("test.txt", "r");
	int* minkHeap = (int*)malloc(sizeof(int) * k);
	if (minkHeap == NULL)
	{
		perror("malloc error");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fin, "%d", &minkHeap[i]);
	}
	//建小堆，使用向下调整
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minkHeap, k, i);
	}
	int val = 0;
	while (!feof(fin))
	{
		fscanf(fin, "%d", &val);
		if (val > minkHeap[0])
		{
			minkHeap[0] = val;
			AdjustDown(minkHeap, k, 0);
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", minkHeap[i]);
	}
}

int main() {
	//createData();
	int k = 10;
	PrintTopK(k);
}