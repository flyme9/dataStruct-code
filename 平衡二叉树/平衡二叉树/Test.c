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
	int leftSize = maxDepth(root->left);//计算出左子树的节点个数
	int rightSize = maxDepth(root->right);//计算出右子树的节点个数
	return leftSize>rightSize ? leftSize + 1 : rightSize + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int leftSize = maxDepth(root->left);
	int rightSize = maxDepth(root->right);
	return abs(leftSize - rightSize)<2//每颗左右子树的层数相差的绝对值小于1
		//将子树进一步划分
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}
int main()
{
	return 0;
}