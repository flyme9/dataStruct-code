#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
bool check(struct TreeNode* left, struct TreeNode* right)
{
	if (!left && !right)
		return true;
	if (left && !right || !left&&right)
		return false;
	if (left->val == right->val)
		return check(left->left, right->right) && check(left->right, right->left);
	return false;
}
bool isSymmetric(struct TreeNode* root) {
	if (!root)
		return true;
	struct TreeNode* left = root->left;
	struct TreeNode* right = root->right;
	return check(left, right);
}
int main()
{
	return 0;
}