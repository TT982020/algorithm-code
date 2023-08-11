#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void TestSList1() {
	int n = 0;
	printf("请输入节点的个数:");
	scanf("%d", &n);
	printf("请输入数据:");
	SLTNode* plist = NULL;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		SLTNode* newnode = BuyListNode(val);
		newnode->next = plist;
		plist = newnode;
	}
	SLTPrint(plist);
	SLTPushBack(&plist, 10000);
	SLTPrint(plist);
}

void TestSList2() {
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	SLTPrint(plist);

	SLTPushFront(&plist, 10);
	SLTPushFront(&plist, 20);
	SLTPushFront(&plist, 30);
	SLTPushFront(&plist, 40);
	SLTPushFront(&plist, 50);

	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);

	SLTPrint(plist);
}

void TestSList3() {
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);

	SLTPrint(plist);
}


void TestSList4() {
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);

	SLTPrint(plist);

	SLTNode* node = SLTFind(plist, 3);
	SLTInsert(&plist, node, 100);

	SLTPrint(plist);
}
int main() {
	//TestSList1();
	//TestSList3();
	TestSList4();
}