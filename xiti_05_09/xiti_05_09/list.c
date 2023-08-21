#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
// 创建返回链表的头结点.
ListNode* ListCreate() {
	ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
	if (newhead == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	newhead->_data = -1;
	newhead->_next = newhead;
	newhead->_prev = newhead;
	return newhead;
}

ListNode* BuyNode(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	node->_data = x;
	return node;
}
// 双向链表销毁
void ListDestory(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->_next;
	ListNode* next = cur->_next;
	while (cur != pHead)
	{
		free(cur);
		cur = next;
		next = cur->_next;
	}
	free(pHead);
}

// 双向链表打印
void ListPrint(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
		
	}
	printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* tmp = BuyNode(x);
	ListNode* tail = pHead->_prev;
	tail->_next = tmp;
	tmp->_prev = tail;
	tmp->_next = pHead;
	pHead->_prev = tmp;
}

// 双向链表尾删
void ListPopBack(ListNode* pHead) {
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* del = pHead->_prev;
	ListNode* last = del->_prev;
	pHead->_prev = last;
	last->_next = pHead;
	free(del);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* tmp = BuyNode(x);
	tmp->_next = pHead->_next;
	pHead->_next->_prev = tmp;
	pHead->_next = tmp;
	tmp->_prev = pHead;
}
// 双向链表头删
void ListPopFront(ListNode* pHead) {
	assert(pHead);
	assert(pHead->_next != pHead);
	ListNode* del = pHead->_next;
	pHead->_next = del->_next;
	del->_next->_prev = pHead;
	free(del);
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x) {
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* tmp = BuyNode(x);
	ListNode* posPrev = pos->_prev;

	tmp->_next = pos;
	pos->_prev = tmp;

	posPrev->_next = tmp;
	tmp->_prev = posPrev;
	
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}

void LTSize(ListNode* phead) {
	assert(phead);
	ListNode* cur = phead->_next;
	int size = 0;
	while (cur != phead)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}