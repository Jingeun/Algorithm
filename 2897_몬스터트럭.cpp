#include <stdio.h>
char grid[51][51];
int result[5];
int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			scanf("%c", &grid[i][j]);
			while(grid[i][j] =='\n')
				scanf("%c", &grid[i][j]);
		}
	int xx[] = { 0,1,0,1 }, yy[] = {0,0,1,1};
	for (int i = 0; i < R - 1; i++) {
		for (int j = 0; j < C - 1; j++) {
			int point = 0, park = 0;
			for (int k = 0; k < 4; k++) {
				if (grid[i + xx[k]][j + yy[k]] == '.') point++;
				else if (grid[i + xx[k]][j + yy[k]] == 'X') park++;
			}
			if (point + park == 4) result[park]++;
		}
	}
	for (int i = 0; i < 5; i++)
		printf("%d\n", result[i]);
}