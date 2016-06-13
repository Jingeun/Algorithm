#include <stdio.h>
int grid[65][65];
int sum(int x, int y, int n) {
	int result = 0;
	for (int i = x; i < x + n; i++) for (int j = y; j < y + n;j++) result += grid[i][j];
	return result;
}
void Quad(int x, int y, int n) {
	int total = sum(x, y, n);
	if(total==0 || total == n*n) printf("%d", total == 0 ? 0 : 1);
	else {
		printf("(");
		Quad(x, y, n / 2);
		Quad(x, y + n / 2, n / 2);
		Quad(x + n / 2, y, n / 2);
		Quad(x + n / 2, y + n / 2, n / 2);
		printf(")");
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &grid[i][j]);
	Quad(0,0,n);
	printf("\n");
}