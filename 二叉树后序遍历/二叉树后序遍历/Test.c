#define _CRT_SECURE_NO_WARNINGS 1
#include<msrdc.h>
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
void PostOder(struct TreeNode* root, int* arr, int* size)
{
	if (root == NULL)
		return;
	PostOder(root->left, arr, size);
	PostOder(root->right, arr, size);
	arr[*size] = root->val;
	(*size)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	int size = TreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*size);
	PostOder(root, arr, returnSize);
	return arr;
}
int main()
{
	return 0;
}