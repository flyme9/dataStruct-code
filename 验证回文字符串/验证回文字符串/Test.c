#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
bool isPalindrome(char * s)
{
	for (int left = 0, right = strlen(s) - 1; left<right; left++, right--)
	{
		while (!isalnum(s[left]) && left<right)
		{	//如果left指向元素既不是数字也不是字母，则指向下一个元素
			left++;
		}
		while (!isalnum(s[right]) && left<right)
		{	//如果right指向元素既不是数字也不是字母，则指向下一个元素
			right--;
		}
		//将指向的两个元素转为小写，然后进行判断是否相等，不是表示字符串不是回文字符串
		if (tolower(s[left]) != tolower(s[right]) && left<right)
			return false;
	}
	return true;
}
int main()
{
	char str[] = "name:123";
	int i= isPalindrome(str);
	printf("%d\n", i);
	return 0;
}