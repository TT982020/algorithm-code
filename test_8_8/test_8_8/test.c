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
}
int main() {
	//TestSList1();
	TestSList2();
}