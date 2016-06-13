#include <stdio.h>
#include <stdlib.h>
typedef struct node { int a, b; }node;
node data[101];
int dp[101];
int comp(const void *a, const void *b) {
	int aa = *(int *)a, bb = *(int *)b;
	return aa > bb;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &data[i].a, &data[i].b);
	qsort(data, n, sizeof(data[0]), comp);
	int max = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (data[j].a < data[i].a && data[j].b < data[i].b && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
			if (dp[i] > max) max = dp[i];
		}
	}	
	printf("%d\n", n - max);
}