// 二叉树最近公共祖先.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	/* 当前节点为p、q、NULL都返回本身即可 */
	if (root == q || root == p || !root) {
		return root;
	}
	/* 递归处理左子树 */
	struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
	/* 递归处理右子树 */
	struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
	/* 处理当前根节点 */
	/* 当前节点左右子树均不为NULL，则找到公共祖先 */
	if (left != NULL && right != NULL) {
		return root;
	}
	if (left == NULL && right != NULL) {    /* 左子树未发现p、q、右子树发现p、q */
		return right;
	}
	else if (left != NULL && right == NULL) { /* 右子树未发现p、q、左子树发现p、q */
		return left;
	}
	else {   /* 左、右子树均未发现p、q */
		return NULL;
	}
}
int main()
{
	return 0;
}