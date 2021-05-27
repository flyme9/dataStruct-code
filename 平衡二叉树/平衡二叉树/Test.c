#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int leftSize = maxDepth(root->left);//������������Ľڵ����
	int rightSize = maxDepth(root->right);//������������Ľڵ����
	return leftSize>rightSize ? leftSize + 1 : rightSize + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int leftSize = maxDepth(root->left);
	int rightSize = maxDepth(root->right);
	return abs(leftSize - rightSize)<2//ÿ�����������Ĳ������ľ���ֵС��1
		//��������һ������
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}
int main()
{
	return 0;
}