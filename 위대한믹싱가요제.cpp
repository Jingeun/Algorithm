#include <stdio.h>
#include <string.h>
int N, M, C, max = 0;
char data[501][8];

int check(int n, int m) {
	if (strstr(data[n], data[m])) return 1;
	if (strstr(data[m], data[n])) return 1;
	return -1;
}

int solve(int n, int count, int target, int limit){
	if (count == M) return target;
	int m = -1, place = -1;
	for (int i = n + 1; i <= limit+1 && i < N; i++) {
		if (check(n, i)) {
			int l1 = strlen(data[target]);
			int l2 = strlen(data[i]);
			int tmp = solve(i, count + 1, l1 > l2 ? i : target, limit);
			if (tmp != -1) {
				int length = strlen(data[tmp]);
				if (m < length) {
					m = length;
					place = tmp;
				}
			}
		}
	}
	return place;
}

int main() {
	scanf("%d %d %d", &N, &M, &C);
	for (int i = 0; i < N; i++)
		scanf("%s", &data[i]);
	for (int i = 0; i < N; i++) {
		int tmp = solve(i, 0, i, i+M);
		if (tmp != -1)
			max += strlen(data[tmp]);
	}
	printf("%d\n", max);
}