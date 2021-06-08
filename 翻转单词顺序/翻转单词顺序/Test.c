#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
char* reverseWords(char* s) {
	int len = strlen(s);
	char* res = (char*)malloc(sizeof(char) * (len + 1));
	int cur = 0, index = 0;
	int left = len - 1, right = len - 1;
	while (left >= 0)
	{
		if (s[left] == ' ')
		{
			left--;
		}
		else
		{
			right = left;
			while (left >= 0 && s[left] != ' ') {
				left--;
			}
			cur = left + 1;
			while (cur <= right) {
				res[index++] = s[cur++];
			}
			res[index++] = ' ';
		}
	}
	if (index > 0 && res[index - 1] == ' ') {
		/* ԭ�ַ������ַ������ */
		res[index - 1] = '\0';
	}
	else {
		/* ԭ�ַ���Ϊ�ջ���ȫΪ�ո����� */
		res[index] = '\0';
	}
	return res;
}