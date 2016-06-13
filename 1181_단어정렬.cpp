#include <stdio.h>

char arr[24][20002];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);

	

	for (int i = 1; i <= n; i++)
		printf("%s\n", arr[i]);
}