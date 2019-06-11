

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int getCommonStrLength(char* pFirstStr, char* pSecondStr) {
	if (pFirstStr == NULL || pSecondStr == NULL) {
		return NULL;
	}
	int len1 = strlen(pFirstStr);
	int len2 = strlen(pSecondStr);
	int Max = len1 > len2 ? len1 : len2;
	int Min = len1 < len2 ? len1 : len2;
	int maxlen = 0;
	int count = 0;
	int start1 = 0, start2 = 0;
	for (int i = 0; pFirstStr[i] != '\0'; i++) {
		for (int j = 0; pSecondStr != '\0'; j++) {
			start1 = i;
			start2 = j;
			while (pFirstStr[start1] == pSecondStr[start2] && start1 < len1 && start2 < len2) {
				start1++;
				start2++;
				count++;
			}
			if (count > maxlen) {
				maxlen = count;
			}
			count = 0;
		}
	}
	return maxlen;
}
int main() {
	char str1[10000] = { 0 };
	char str2[10000] = { 0 };
	scanf("%s %s", str1, str2);
	cout << getCommonStrLength(str1, str2) << endl;
	system("pause");
	return 0;
}
