// �����������������.cpp : �������̨Ӧ�ó������ڵ㡣
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
	/* ��ǰ�ڵ�Ϊp��q��NULL�����ر����� */
	if (root == q || root == p || !root) {
		return root;
	}
	/* �ݹ鴦�������� */
	struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
	/* �ݹ鴦�������� */
	struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
	/* ����ǰ���ڵ� */
	/* ��ǰ�ڵ�������������ΪNULL�����ҵ��������� */
	if (left != NULL && right != NULL) {
		return root;
	}
	if (left == NULL && right != NULL) {    /* ������δ����p��q������������p��q */
		return right;
	}
	else if (left != NULL && right == NULL) { /* ������δ����p��q������������p��q */
		return left;
	}
	else {   /* ����������δ����p��q */
		return NULL;
	}
}
int main()
{
	return 0;
}