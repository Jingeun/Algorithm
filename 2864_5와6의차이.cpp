#include <stdio.h>
#include <string.h>
char A[1000001], B[1000001];
int main() {
	scanf("%s %s", &A, &B);

	int result_max = 0, result_min = 0, ALength = strlen(A), BLength = strlen(B);
	for (int i = ALength-1, j=1; i >= 0; i--,j*=10) {
		if (A[i] == '5') result_max += 6*j;
		else result_max += (A[i] - '0')*j;
		if (A[i] == '6') result_min += 5 * j;
		else result_min += (A[i] - '0')*j;
	}
	for (int i = BLength - 1, j = 1; i >= 0; i--, j *= 10) {
		if (B[i] == '5') result_max += 6 * j;
		else result_max += (B[i] - '0')*j;
		if (B[i] == '6') result_min += 5 * j;
		else result_min += (B[i] - '0')*j;
	}
	printf("%d %d\n", result_min, result_max);
}