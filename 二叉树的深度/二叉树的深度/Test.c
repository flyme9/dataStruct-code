#define _CRT_SECURE_NO_WARNINGS 1
#include<stdarg.h>
struct TreeNode
{
int val;
struct TreeNode *left;
struct TreeNode *right;
};
int maxDepth(struct TreeNode* root) {
	if (!root) {
		return 0;
	}
	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
	int head = 0, rear = 0;
	queue[rear++] = root;
	int depth = 0;
	while (head < rear) {
		int curRear = rear;
		depth++;
		for (; head < curRear; head++) {
			if (queue[head]->left) {
				queue[rear++] = queue[head]->left;
			}
			if (queue[head]->right) {
				queue[rear++] = queue[head]->right;
			}
		}
	}
	return depth;
}