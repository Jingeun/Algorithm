#include <stdio.h>
int grid[52][52], map[52][52];
int front, rear, max = 0, n, m;
typedef struct node { int x, y; }node;
node queue[9999];
void init() {
	front = rear = 0;
	for (int i = 0; i < n + 1; i++) for (int j = 0; j < m + 1; j++) map[i][j] = grid[i][j];
}
void enqueue(int x, int y) {
	queue[rear].x = x; queue[rear++].y = y; map[x][y] = 0;
}
int BFS() {
	int count = 0, dir[][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
	for (; rear != front; count++) {
		int size = rear - front;
		for (int i = 0; i < size; i++, front++) {
			for (int j = 0; j < 4; j++)
				if (map[queue[front].x + +dir[j][0]][queue[front].y + dir[j][1]] == 1)
					enqueue(queue[front].x + +dir[j][0], queue[front].y + dir[j][1]);
		}
	}
	return count - 1;
}
int main() {
	char tmp;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%c", &tmp); while (tmp == '\n') scanf("%c", &tmp);
			grid[i][j] = tmp == 'L' ? 1 : 0;
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == 1) {
				init();
				enqueue(i, j);
				int cnt = BFS();
				if (max < cnt) max = cnt;
			}
		}
	printf("%d\n", max);
	return 0;
}