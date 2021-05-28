#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* solve(char* s, char* t) {
	int slen = strlen(s);
	int tlen = strlen(t);
	int maxlen = slen > tlen ? slen + 1 : tlen + 1;
	char* res = (char *)calloc(maxlen + 1, sizeof(char));
	int i = 0, j = 0, k = 0;
	int temp = 0;
	for (i = slen - 1, j = tlen - 1, k = maxlen - 1; k >= 0; i--, j--, k--) {
		int stemp = 0;
		if (i >= 0) {
			stemp = s[i] - '0';
		}

		int ttemp = 0;
		if (j >= 0) {
			ttemp = t[j] - '0';
		}

		temp += stemp + ttemp;
		res[k] = temp % 10 + '0';
		temp = temp / 10;
	}
	if (*res == '0')
		return ++res;

	return res;
}
int main()
{
	char str[] = "1";
	char srr1[] = "99";
	char* arr = solve(str, srr1);
	printf("%s", arr);
	return 0;
}