#include <stdio.h>
#include <string.h>
char str[10002];
int alpha[26];
int main() {
	char a;
	scanf("%s", str);
	for (int i = 0; i<strlen(str); i++)
		alpha[str[i] - 'A']++;
	for (int i = 0; i < 26; i++)
		if (alpha[i] != 0)
			for (int j = 0; j < alpha[i]; j++)
				printf("%c", 'A' + i);
}