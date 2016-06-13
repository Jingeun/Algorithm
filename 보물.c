#include <stdio.h>
#define SWAP(x, y){int tmp = x; x = y; y = tmp;}
int main() {
	int A[51], B[51];
	int n, i, j, sum = 0;
	scanf("%d", &n);

	for (i = 0; i<n; i++) scanf("%d", &A[i]);
	for (i = 0; i<n; i++) scanf("%d", &B[i]);

	for (i = 1; i<n; i++)
		for (j = 0; j<i; j++) {
			if (A[i]>A[j]) SWAP(A[i], A[j]);
			if (B[i]<B[j]) SWAP(B[i], B[j]);
		}

	for (i = 0; i<n; i++) sum += (A[i] * B[i]);
	printf("%d\n", sum);
	return 0;
}