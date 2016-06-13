#include <stdio.h>
int grid[51][51][51];
int recursion(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (grid[a][b][c] != 0) return grid[a][b][c];
	if (a > 20 || b > 20 || c > 20) return grid[a][b][c] = recursion(20, 20, 20);
	if (a < b && b < c)  return grid[a][b][c] = recursion(a, b, c - 1) + recursion(a, b - 1, c - 1) - recursion(a, b-1, c);
	return grid[a][b][c] = recursion(a - 1, b, c) + recursion(a - 1, b - 1, c) + recursion(a - 1, b, c - 1) - recursion(a - 1, b - 1, c - 1);
}
int main() {
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, recursion(a, b, c));
	}
}