#include <stdio.h>
#define queueSize 999999
typedef struct node { int x, y; } node;
node grid[100003], queue[queueSize];
int front=0, rear=0;
long long int min = 99999999999, count = 0;
void enqueue(int x, int y) {
	queue[rear].x = x;
	queue[rear++].y = y;
	if (rear == queueSize) rear = 0;
}
void solve(node tmp) {
	int i, x, y;
	int size = rear - front;
	int xx[5] = { -1,0,1,0,0 }, yy[5] = { 0,-1,0,1,0 }, distance[5][3];
	while (size--) {
		for (i = 0; i < 5; i++) {
			x = tmp.x - queue[front].x + xx[i];
			if (x < 0) x *= -1;
			y = tmp.y - queue[front].y + yy[i];
			if (y < 0) y *= -1;
			distance[i][0] = x + y;
			distance[i][1] = tmp.x + xx[i];
			distance[i][2] = tmp.y + yy[i];
		}
		front++;
		if (front == queueSize) front = 0;
	}
	for (i = 0; i < 5; i++)
		if (min>distance[i][0])
			min = distance[i][0];
	for (i = 0; i < 5; i++)
		if (distance[i][0] == min)
			enqueue(distance[i][1], distance[i][2]);
}
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
		scanf("%d %d", &grid[i].x, &grid[i].y);
	enqueue(grid[0].x, grid[0].y);

	for (i = 1; i <= n; i++) {
		min = 99999999999;
		solve(grid[i]);
		count += min;
	}
	printf("%lld\n", count);
}