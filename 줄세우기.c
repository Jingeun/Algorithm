#include <stdio.h>

int arr[201], LIS[201];
int main() {
	int N, i, j, count = 0, max = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < N; i++) {
		LIS[i] = 1;
		for (j = 0; j < i; j++)
			if (arr[i]>arr[j] && LIS[i] < LIS[j] + 1) {
				LIS[i] = LIS[j] + 1;
				if (max < LIS[i])
					max = LIS[i];
			}
	}

	printf("%d\n", N - max);
	return 0;
}