#include <stdio.h>
#include <string.h>
int arr[50001], sumArr[50001][3];
int n, size, sumArrSize, max;
int solve(int pos, int cnt) {
	if (sumArr[pos][cnt] != 0)
		return sumArr[pos][cnt];
	int tmpMax = 0;
	for (int i = pos + size; i < sumArrSize; i++) {
			sumArr[i][cnt + 1] = solve(i, cnt + 1);
		if (sumArr[i][cnt + 1] > tmpMax)
			tmpMax = sumArr[i][cnt + 1];
	}
	return sumArr[pos][cnt] = sumArr[pos][2] + tmpMax;
} 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &size);

	sumArrSize = max = 0;
	for (int i = size-1; i < n; i++, sumArrSize++) {
		for (int j = i; j > i - size; j--)
			sumArr[sumArrSize][2] += arr[j];
	}
	for (int i = 0; i < sumArrSize; i++) {
		int tmp = solve(i, 0);
		if (max < tmp) max = tmp;
	}
	printf("%d\n", max);
	return 0;
}