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

int main() {
	int a[] = { 100,2,3,89,5,4,66 };
	int n = sizeof(a) / sizeof(int);
	/*HeapSort1(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}*/
	HeapSort2(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}