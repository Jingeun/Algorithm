#include <stdio.h>
char grid[102][102];
int main() {
	int R, C, i, j;
	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++) {
			scanf("%c", &grid[i][j]);
			while(grid[i][j] == '\n' || grid[i][j] == '\0')
				scanf("%c", &grid[i][j]);
		}

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++) 
			grid[i][2 * C - 1 - j] = grid[i][j];
	
	for (i = 0; i < 2 * R; i++)
		for (j = 0; j < 2 * C; j++)
			grid[2*R-1-i][j] = grid[i][j];

	scanf("%d %d", &i, &j);
	grid[i - 1][j - 1] = grid[i - 1][j - 1] == '#' ? '.' : '#';
	for (i = 0; i < 2 * R; i++) {
		for (j = 0; j < 2 * C; j++)
			printf("%c", grid[i][j]);
		printf("\n");
	}
}