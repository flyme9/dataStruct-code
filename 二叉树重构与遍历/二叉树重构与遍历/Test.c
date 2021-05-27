#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef char TDataType;
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	TDataType data;
}TNode;
//二叉树重构
TNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		//当指向的元素为#时，表示该节点为NULL
		(*pi)++;
		return NULL;
	}
	//开辟空间，创建一颗树
	TNode* root = (TNode*)malloc(sizeof(TNode));
	if (root == NULL)
	{
		//空间开辟失败，终止程序
		printf("malloc fail\n");
		exit(-1);
	}
	root->data = str[*pi];
	(*pi)++;
	root->left = CreateTree(str, pi);
	root->right = CreateTree(str, pi);
	return root;
}
//中序遍历
void InOrder(TNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//中序遍历，左子树，根，右子树
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//后序遍历
void PostOrder(TNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//后序遍历，左子树，右子树，根
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
int main()
{
	//以前序遍历顺序输入
	char str[100];
	scanf("%s", str);
	int i = 0;
	TNode* root = CreateTree(str, &i);
	PostOrder(root);
	return 0;
}