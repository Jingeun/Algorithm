#include <stdio.h>
#include <string.h>
char str[1000002];
int stack[1000002];
char result[1000002];
int top = 0, tokenCnt = 0;
int main() {
	char target[40];
	scanf("%s", str);
	int strLength = strlen(str);
	scanf("%s", target);
	int targetLength = strlen(target);
	int cnt = 0;
	for (int i = 0, remove = 1; i < strLength; i++, cnt++) {
		if (str[i] == target[0]) stack[++top]++;
		else if (str[i] == target[stack[top]]) stack[top]++;
		else stack[top] = 0;

		result[cnt] = str[i];

		if (stack[top] == targetLength) {
			cnt = i - targetLength*remove;
			stack[top--] = 0;
			remove++;
		}
	}
	if (cnt==0) printf("FRULA");
	else {
		for (int i = 0; i < cnt; i++)
			printf("%c", result[i]);
	}
	return 0;
}