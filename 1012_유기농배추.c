#include <stdio.h>
typedef struct node{ int x, y; }node;
int grid[52][52];
int count, front, rear;
node queue[9999];
void print(int n, int m) {
	int i, j;
	for (i = 0; i <= 12; i++) {
		for (j = 0; j <= 12; j++)
			printf("%2d", grid[i][j]);
		printf("\n");
	}
	printf("\n");
}
void init(){
	int i, j;
	count = front = rear = 0;
	for (i = 0; i < 52; i++)
		for (j = 0; j < 52; j++)
			grid[i][j] = 0;
}
node newnode(int x, int y){
	node tmp; tmp.x = x; tmp.y = y;
	return tmp;
}
void grassfire(int M, int N){
	int i, j, k;
	int xx[] = {-1,0,1,0}, yy[] = {0,1,0,-1};
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++) {
			if (grid[i][j] == 1) {
				queue[rear++] = newnode(i, j);
				grid[i][j] = 0;
				while ((rear - front) != 0) {
					for (k = 0; k < 4; k++)
						if (grid[queue[front].x + xx[k]][queue[front].y + yy[k]] == 1) {
							grid[queue[front].x + xx[k]][queue[front].y + yy[k]] = 0;
							queue[rear++] = newnode(queue[front].x + xx[k], queue[front].y + yy[k]);
						}
					front++;
				}
				count++;
			}
		}
}

int main(){
	int testcase, M, N, K, x, y;
	
	scanf("%d", &testcase);
	while (testcase--){
		scanf("%d %d %d", &M, &N, &K);
		init();
		while (K--){
			scanf("%d %d", &x, &y);
			grid[x+1][y+1] = 1;
		}
		print(M, N);
		grassfire(M, N);
		printf("%d\n", count);
	}
}