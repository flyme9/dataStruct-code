#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char* reverseLeftWords(char* s, int n)
{
	//int left = 0, right = strlen(s) - 1;
	for (int i = 0; i<n; i++)
	{
		int left = 0, right = strlen(s);
		char tmp = s[left];
		while (left<right)
		{
			s[left] = s[left+1];
			left++;
		}
		s[right-1] = tmp;
		//right--;
	}
	return s;
}
int main()
{
	char str[] = "abcdef";
	printf("%s ", reverseLeftWords(str, 2));
	return 0;
}