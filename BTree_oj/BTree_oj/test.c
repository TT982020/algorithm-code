#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;    
};
//相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//单值二叉树
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

//对称二叉树
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


//二叉树的前序遍历
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

//二叉树的中序遍历

//二叉树的后序遍历
int main() {

}