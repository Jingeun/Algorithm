#include <stdio.h>
typedef struct node {
	int x, y;
} node;
node queue[99999];
int front = 0, rear = 0, count = 1;
int grid[105][105];
void enqueue(int x, int y) {
	queue[rear].x = x;
	queue[rear].y = y;
	grid[x][y] = 2;
	rear++;
}
int main() {
	char tmp;
	int n, m, i, j, size, flag = 1;
	int xx[4] = { -1,0,1,0 }, yy[4] = { 0,-1,0,1 };
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%1d", &grid[i][j]);

	enqueue(1, 1);

	while (rear - front != 0 && flag) {
		size = rear - front;
		for (i = 0; i < size && flag; i++) {
			for (j = 0; j < 4 && flag; j++) {
				if (queue[front].x + xx[j] == n && queue[front].y + yy[j] == m) {
					flag = 0;
					break;
				}else if (grid[queue[front].x + xx[j]][queue[front].y + yy[j]] == 1) 
					enqueue(queue[front].x + xx[j], queue[front].y + yy[j]);
			}
			front++;
		}
		count++;
	}
	printf("%d\n", count);
}