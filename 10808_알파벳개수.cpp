#include <stdio.h>
#include <string.h>
int main() {
	int alpha[26] = { 0 };
	char input[101];
	scanf("%s", &input);
	int length = strlen(input);
	for (int i = 0; i<length; i++) alpha[input[i] - 'a']++;
	for (int i = 0; i<26; i++) printf("%d ", alpha[i]);
	return 0;
}