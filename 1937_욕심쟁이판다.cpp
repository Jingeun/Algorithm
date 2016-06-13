#include <stdio.h>
#include <stdlib.h>
int grid[502][502], memo[502][3], dp[502][502];
int comp(const void *aa, const void *bb) {
	int *a = (int *)aa, *b = (int *)bb;
	return a[0] < b[0];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, cnt = 0; i <= n; i++) 
		for (int j = 1; j <= n; j++, cnt++) {
			scanf("%d", &grid[i][j]);
			memo[cnt][0] = grid[i][j];
			memo[cnt][1] = i;
			memo[cnt][2] = j;
		}

	int dir[][2] = { {0,-1},{-1,0},{0,1},{1,0} };

	qsort(memo, n * n, sizeof(memo[0]), comp);

	for (int i = 0; i < n*n; i++) {
		int max = 0, x = memo[i][1], y = memo[i][2];
		for (int j = 0; j < 4; j++) {
			if (memo[i][0] < grid[x + dir[j][0]][y + dir[j][1]] && dp[x + dir[j][0]][y + dir[j][1]] > max)
				max = dp[x + dir[j][0]][y + dir[j][1]];
		}
		dp[x][y] = max + 1;
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			if (max < dp[i][j])
				max = dp[i][j];

	printf("%d\n", max);
}