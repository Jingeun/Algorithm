#include <stdio.h>
int data[10000001] = { 0, 1 };
int main() {
	int n, i;
	scanf("%d", &n);
	printf("%d\n", (n == 0) ? 0 : (n > 0) ? 1 : (n % 2 == 0) ? -1 : 1);
	if (n < 0) n *= -1;
	for (i = 2; i <= n; i++)
		data[i] = (data[i - 1] + data[i - 2]) % 1000000000;
	printf("%d\n", data[n]%1000000000);
}