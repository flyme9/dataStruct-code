#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(int x) {
	if (x < 0) 
		return false;
	int temp = x;
	long n = 0;
	while (temp)
	{
		n = n * 10 + temp % 10;//½«Êý×ÖÄæÐò
		temp /= 10;
	}
	return n == x ? true : false;
}
int main()
{
	bool ret = isPalindrome(121);
	printf("%d ", ret);
	return 0;
}