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
		{	//���leftָ��Ԫ�ؼȲ�������Ҳ������ĸ����ָ����һ��Ԫ��
			left++;
		}
		while (!isalnum(s[right]) && left<right)
		{	//���rightָ��Ԫ�ؼȲ�������Ҳ������ĸ����ָ����һ��Ԫ��
			right--;
		}
		//��ָ�������Ԫ��תΪСд��Ȼ������ж��Ƿ���ȣ����Ǳ�ʾ�ַ������ǻ����ַ���
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