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
	//������������Ľڵ����
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void preorder(struct TreeNode* root, int* res, int* resSize) {
	if (root == NULL) {
		return;
	}
	//�����ڵ����������
	res[*resSize] = root->val;
	(*resSize)++;
	//�ݹ飬��������Ϊ�ܶ�С��
	preorder(root->left, res, resSize);
	preorder(root->right, res, resSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int size = TreeSize(root);
	int* res = malloc(sizeof(int) * size);
	*returnSize = 0;
	preorder(root, res, returnSize);
	return res;
}
int main()
{
	return 0;
}