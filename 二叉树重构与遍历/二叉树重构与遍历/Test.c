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
//�������ع�
TNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		//��ָ���Ԫ��Ϊ#ʱ����ʾ�ýڵ�ΪNULL
		(*pi)++;
		return NULL;
	}
	//���ٿռ䣬����һ����
	TNode* root = (TNode*)malloc(sizeof(TNode));
	if (root == NULL)
	{
		//�ռ俪��ʧ�ܣ���ֹ����
		printf("malloc fail\n");
		exit(-1);
	}
	root->data = str[*pi];
	(*pi)++;
	root->left = CreateTree(str, pi);
	root->right = CreateTree(str, pi);
	return root;
}
//�������
void InOrder(TNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//���������������������������
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//�������
void PostOrder(TNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//���������������������������
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
int main()
{
	//��ǰ�����˳������
	char str[100];
	scanf("%s", str);
	int i = 0;
	TNode* root = CreateTree(str, &i);
	PostOrder(root);
	return 0;
}