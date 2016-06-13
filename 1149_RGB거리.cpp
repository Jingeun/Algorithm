#include <stdio.h>
#define min3(a, b, c) (a > b) ? (b > c) ? c : b : (a > c) ? c : a;
#define min(a, b) a > b ? b : a
int home[1001][3];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n;i++) 
		scanf("%d %d %d", &home[i][0], &home[i][1], &home[i][2]);
	int result = 0;
	for (int i = 1; i < n; i++) {
		home[i][0] += min(home[i - 1][1], home[i - 1][2]);
		home[i][1] += min(home[i - 1][0], home[i - 1][2]);
		home[i][2] += min(home[i - 1][0], home[i - 1][1]);
	}
	result = min3(home[n - 1][0], home[n - 1][1], home[n - 1][2]);
	printf("%d\n", result);
}