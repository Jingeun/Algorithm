#include <stdio.h>
int grid[100002][3];
int min2(int x, int y){ return x > y ? y : x; }
int min3(int x, int y, int z){ return x > y ? y > z ? z : y : x > z ? z : x; }
int main(){
	int n, cnt = 1;
	while (1){
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &grid[i][0], &grid[i][1], &grid[i][2]);
		grid[1][0] += grid[0][1];
		grid[1][1] += min2(grid[0][1], grid[0][1] + grid[0][2]);
		grid[1][2] += min2(grid[0][1], grid[0][1] + grid[0][2]);

		for (int i = 2; i < n; i++){
			grid[i][0] += min2(grid[i-1][0], grid[i-1][0] + grid[i-1][1]);
			grid[i][1] += min2(min2(grid[i - 1][0] + grid[i][0], grid[i - 1][0]), min2(grid[i - 1][1], grid[i - 1][1] + grid[i - 1][2]));
			grid[i][2] += grid[i - 1];
		}
		printf("%d. %d\n", cnt++, grid[n - 1][1]);
	}
}