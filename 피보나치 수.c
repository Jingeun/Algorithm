#include <stdio.h>
int fibo(int n) {
	int i, data[50] = { 0, 1, };
	for (i = 2; i <= n; i++)
		data[i] = data[i - 1] + data[i - 2];
	return data[n];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", fibo(n));
}