#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
int main() {
	HP hp;
	HPInit(&hp);
	int a[] = {32,50,60,100,65,70};
	for (int i = 0; i < 6; i++) {
		HPPush(&hp, a[i]);
	}
	for (int i = 0; i < 6; i++) {
		printf("%d ", hp.a[i]);
	}

}