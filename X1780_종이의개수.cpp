#include <stdio.h>
int grid[2500][2500], result[3]; //0 1 -1
int check(int x, int y, int n) {
	int tmp = grid[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (tmp != grid[i][j])
				return 2;
	return tmp;
}
void solve(int x, int y, int n) {
	int flag = check(x, y, n);
	if (flag == 2) {
		int nn = n / 3;
		solve(x,y,nn);
		solve(x + nn, y, nn);
		solve(x + nn * 2, y, nn);
		solve(x, y + nn, nn);
		solve(x + nn, y + nn, nn);
		solve(x + nn * 2, y + nn, nn);
		solve(x, y + nn * 2, nn);
		solve(x + nn, y + nn * 2, nn);
		solve(x + nn * 2, y + nn * 2, nn);
	}else 
		result[flag == -1 ? 2 : flag]++;
}
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);

	solve(0, 0, n);

	printf("%d\n%d\n%d\n", result[2], result[1], result[0]);
	return 0;
}