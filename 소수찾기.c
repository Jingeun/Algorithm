#include <stdio.h>
int A[1001] = {1,1, 0 };
int main() {
	int n, data[101], i, j, count = 0;;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &data[i]);
	for (i = 2; i < 32; i++) {
		if (A[i] == 0) 
			for (j = i*2; j < 1001; j += i)
				A[j] = 1;
	}
	for (i = 0; i < n; i++)
		if (A[data[i]] == 0) count++;
	printf("%d\n", count);
}