#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Queue.h"
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

//��ͬ����
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//��ֵ������
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL) return true;
    if (root->left && root->left->val != root->val) {
        return false;
    }
    if (root->right && root->right->val != root->val) {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

//�Գƶ�����
bool _isSymmetric(struct TreeNode* leftRoot, struct TreeNode* rightRoot) {
    if (leftRoot == NULL && rightRoot == NULL) return true;
    if (leftRoot == NULL || rightRoot == NULL) return false;
    if (leftRoot->val != rightRoot->val) return false;
    return _isSymmetric(leftRoot->left, rightRoot->right)
        && _isSymmetric(leftRoot->right, rightRoot->left);
}
bool isSymmetric(struct TreeNode* root) {
    return _isSymmetric(root->left, root->right);
}


//��������ǰ�����
int BTSize(struct TreeNode* root) {
    return root == NULL ? 0 : BTSize(root->left) + BTSize(root->right) + 1;
}
void _preorder(struct TreeNode* root, int* a, int* pi) {
    if (root == NULL) return;
    a[(*pi)++] = root->val;
    _preorder(root->left, a, pi);
    _preorder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = BTSize(root);
    int* a = (int*)malloc(sizeof(struct TreeNode) * (*returnSize));
    int i = 0;
    _preorder(root, a, &i);
    return a;
}

//���������������

//�������ĺ������

//�������
void LevelOrder(struct TreeNode* root) {
    Que q;
    QueueInit(&q);
    QueuePush(&q, root);
    while (!QueueEmpty(&q))
    {
        TreeNode* tmp = QueueFront(&q);
        printf("%d ", tmp->val);
        QueuePop(&q);
        if (tmp->left)
        {
            QueuePush(&q, tmp->left);
        }
        if (tmp->right)
        {
            QueuePush(&q, tmp->right);
        }
    }
    QueueDestroy(&q);
}

//������������
void BTDestroy(TreeNode* root) {
    if (root == NULL)
    {
        return;
    }
    BTDestroy(root->left);
    BTDestroy(root->right);
    free(root);
}


TreeNode* BuyNode(int data) {
    TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
    if (tmp == NULL)
    {
        perror("malloc failed");
        return NULL;
    }
    tmp->val = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
//�ж�һ�����ǲ�����ȫ������
//�ж�׼�򣺲���������ڵ�ΪNULLҲ����У�������������NULLʱ���������ľ�ΪNULL ��Ϊ
//��ȫ����������������ȫ������
bool BTComplete(TreeNode* root) {
    Que q;
    QueueInit(&q);
    if (root)
    {
        QueuePush(&q, root);
    }
    while (!QueueEmpty(&q))
    {
        TreeNode* front = QueueFront(&q);
        QueuePop(&q);
        if (front == NULL)
        {
            break;
        }
        QueuePush(&q, front->left);
        QueuePush(&q, front->right);
    }
    while (!QueueEmpty(&q))
    {
        TreeNode* front = QueueFront(&q);
        QueuePop(&q);
        if (front != NULL)
        {
            QueueDestroy(&q);
            return false;
        }
    }
    QueueDestroy(&q);
    return true;
}

TreeNode* CreatBinaryTree()
{
    TreeNode* node1 = BuyNode(1);
    TreeNode* node2 = BuyNode(2);
    TreeNode* node3 = BuyNode(3);
    TreeNode* node4 = BuyNode(4);
    TreeNode* node5 = BuyNode(5);
    TreeNode* node6 = BuyNode(6);
    TreeNode* node7 = BuyNode(7);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;
    node2->right = node7;
    return node1;
}
int main() {
    TreeNode* root = CreatBinaryTree();
    LevelOrder(root);
    printf("\n");

    bool ret = BTComplete(root);
    printf("%d", ret);

    BTDestroy(root);
    root = NULL;
}