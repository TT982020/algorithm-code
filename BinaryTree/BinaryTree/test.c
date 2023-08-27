#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int BTDataType;

typedef struct BinaryTreeNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x) {
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->left = node7;
	return node1;
}


void PreOrder(BTNode* root) {
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//int size = 0;
//void BTSize(BTNode* root) {
//	if (root==NULL)
//	{
//		return;
//	}
//	++size;
//	BTSize(root->left);
//	BTSize(root->right);
//	return;
//}

int BTSize(BTNode* root) {
	if (root==NULL)
	{
		return 0;
	}
	return BTSize(root->left) + BTSize(root->right) + 1;
}

int BTLeafSize(BTNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BTLeafSize(root->left) + BTLeafSize(root->right);
}

int BTHeight(BTNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int leftH = BTHeight(root->left);
	int rightH = BTHeight(root->right);
	return leftH > rightH ? leftH + 1 : rightH + 1;
}

int BTLevelKSize(BTNode* root, int k) {
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k==1)
	{
		return 1;
	}
	return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType data) {
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}
	BTNode* ret1 = BinaryTreeFind(root->left, data);
	if (ret1)
	{
		return ret1;
	}
	BTNode* ret2 = BinaryTreeFind(root->right, data);
	if (ret2)
	{
		return ret2;
	}
	return NULL;
}

int main() {
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	/*size = 0;
	BTSize(root);
	printf("%d\n",size);

	size = 0;
	BTSize(root);
	printf("%d\n", size);

	size = 0;
	BTSize(root);
	printf("%d\n", size);*/

	int size = BTSize(root);
	printf("size = %d\n", size);

	int h = 0;
	h = BTHeight(root);
	printf("height = %d\n", h);

	int ks = 0;
	ks = BTLevelKSize(root, 3);
	printf("k level size = %d\n", ks);
	ks = BTLevelKSize(root, 4);
	printf("k level size = %d\n", ks);

	BTNode* node = BinaryTreeFind(root, 3);
	printf("find node data is %d\n", node->data);
}