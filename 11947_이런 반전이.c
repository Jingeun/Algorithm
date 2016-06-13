#include <stdio.h>

long long int find(long long int n) {
	long long int half = 10;
	while ((n/=10) != 0) half *= 10;
	return half;
}
int main() {
	int n;
	long long int a, result, check;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &a);
		check = find(a);
		printf("%lld\n", (a >= check / 2)?check/2 * ((check-1)-(check/2)): a * ((check - 1) - a));
	}
	return 0;
}
