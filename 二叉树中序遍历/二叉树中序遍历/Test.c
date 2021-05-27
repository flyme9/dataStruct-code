#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void InOrder(struct TreeNode* root, int* arr, int* size)
{
	if (root == NULL)
		return;
	InOrder(root->left, arr, size);
	arr[*size] = root->val;
	(*size)++;
	InOrder(root->right, arr, size);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	int size = TreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*size);
	InOrder(root, arr, returnSize);

	return arr;
}
int main()
{
	return 0;
}