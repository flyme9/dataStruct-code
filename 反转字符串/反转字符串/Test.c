#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void reverseString(char* s, int sSize) {
	int left = 0, right = sSize-1;
	while (left<right)
	{
		char tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		left++;
		right--;
	}
}
int main()
{
	char str[] = "hello world";
	reverseString(str, strlen(str));
	printf("%s", str);
	return 0;
}