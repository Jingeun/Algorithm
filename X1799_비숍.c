#include <stdio.h>
typedef struct node{ int x,y; }node;
node dfs[10010];
int grid[12][12], visit[101][101], max = 0, count = 0, nodeCnt = 0;
void newNode(int x, int y) {
	dfs[nodeCnt].x = x;
	dfs[nodeCnt++].y = y;
}
void going(int x, int y, int n) {
	int i = x, j = y;
	count = n > 0 ? count + 1 : count - 1;
	grid[i][j] += n;
	while (grid[--i][--j] > 0) grid[i][j] += n;
	i = x; j = y;
	while (grid[++i][--j] > 0) grid[i][j] += n;
	i = x; j = y;
	while (grid[--i][++j] > 0) grid[i][j] += n;
	i = x; j = y;
	while (grid[++i][++j] > 0) grid[i][j] += n;
}
void bishop(int x) {
	int i, j;
	if (grid[dfs[x].x][dfs[x].y] == -1) return;
	if (grid[dfs[x].x][dfs[x].y] >= 2) return;
	going(dfs[x].x, dfs[x].y, 2);
	if (max < count) max = count;
	for (i = 0; i < nodeCnt; i++) {
		if (visit[x][i] != 1 && grid[dfs[i].x][dfs[i].y] == 1) {
			visit[x][i] = 1;
			bishop(i);
		}
	}
	going(dfs[x].x, dfs[x].y, -2);
}
int main() {
	int n, i, j, k, count = 0, m;
	scanf("%d", &n);
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++) {
			if (i >= 1 && i <= n && j >= 1 && j <= n) {
				scanf("%d", &grid[i][j]);
				if (grid[i][j] == 1) newNode(i, j);
			}else grid[i][j] = -1;
		}
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++) {
			if (i >= 1 && i <= n && j >= 1 && j <= n) {
				grid[i][j] = 1;
				newNode(i, j);
			}
		}

	//´õºí¸´
	//scanf("%d", &m);
	//for (i = 0; i < m; i++) {
	//	scanf("%d %d", &j, &k);
	//	grid[j][k] = 0;
	//}

	for (i = 0; i < nodeCnt; i++) {
		for (j = 0; j < 101; j++)
			for (k = 0; k < 101; k++)
				visit[j][k] = 0;
		if(grid[dfs[i].x][dfs[i].y]==1)
			bishop(i);
	}
	printf("%d\n", max);
}