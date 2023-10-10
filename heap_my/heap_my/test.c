#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
void CreateNDate()
{
	// 造数据
	int n = 100;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}


void PrintTopK(int k) {
	
	FILE* fin = fopen("data.txt", "r");
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
	/*CreateNDate();
	PrintTopK(10);*/
	Heap hp;
	
	int a[] = {32,50,60,100,65,70};
	HeapCreate(&hp, a, 6);
	printf("\n");
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
	for (int i = 0; i < 6; i++) {
		printf("%d ", hp._a[i]);
	}

	printf("\n");
	HeapSort(a, 6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
}