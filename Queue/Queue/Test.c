#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
void menu()
{
	printf("+----------------------------+\n");
	printf("| 1.数据入队      2.数据出队 |\n");
	printf("| 3.数据个数      0.退出     |\n");
	printf("+----------------------------+\n");
}
void Test()
{
	Queue q;
	QueueInit(&q);
	int n = 0, Input = 0, line = 0;
	QDataType x;
	menu();
	do
	{
		if (line > 10)
		{
			system("cls");
			menu();
			line = 0;
		}
		printf("请输入需要操作的选项序号( 0 - 3 ):>");
		scanf("%d", &Input);
		switch (Input)
		{
		case PUSH:
			printf("请输入需要插入数据的个数:>");
			scanf("%d", &n);
			printf("请输入数据:>");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &x);
				QueuePush(&q, x);
			}
			line++;
			break;
		case POP:
			while (!QueueEmpty(&q))
			{
				printf("%d ", QueueFront(&q));
				QueuePop(&q);
			}
			printf("\n");
			line++;
			break;
		case SIZE:
			printf("%d \n", QueueSize(&q));
			break;
		case EXIT:
			QueueDestroy(&q);
			line++;
			break;
		default:
			printf("选项序号非法\n");
			line++;
			break;
		}
	} while (Input);
}
int main()
{
	Test();
	return 0;
}