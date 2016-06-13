#include <stdio.h>
int main() {
	int n, result = 0, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		result += (i != n - 1) ? tmp - 1 : tmp;
	}
	printf("%d\n", result);
}