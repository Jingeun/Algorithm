#include <stdio.h>
int A[51], B[51];
int main() {
	int n, i, j, cnt;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < n; i++) {
		cnt = 0;
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			else if (A[i] > A[j]) cnt++; 
			else if (A[i] == A[j] && i>j) cnt++;
		}
		B[i] = cnt;
	}

	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
}