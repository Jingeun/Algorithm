#include <stdio.h>
typedef struct node{ int x, y; }node;
node queue[999999];
int front = 0, rear = 0, cnt = 0;
int grid[1005][1005];
void enqueue(int x, int y){
	queue[rear].x = x;
	queue[rear++].y = y;
}
//2->익지않은 토마토, 1-> 익은 토마토, -1->토마토가 들어있지 않은 칸, 0->토마토창고 밖
int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++){
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == 0) grid[i][j] = 2;
			else if (grid[i][j] == 1) enqueue(i, j);

			if (grid[i][j] == 1 || grid[i][j] == -1) cnt++;
		}
	int result = 0;
	if (rear - front == N*M){  result = 1;
	}else if (rear == 0){ result = 0;
	}else{
		int xx[] = {-1,1,0,0}, yy[] = {0,0,-1,1}; //왼 오 상 하
		while (rear != front){
			int size = rear - front;
			for (int i = 0; i < size; i++){
				for (int k = 0; k < 4; k++){
					if (grid[queue[front].x + xx[k]][queue[front].y + yy[k]] == 2){
						enqueue(queue[front].x + xx[k], queue[front].y + yy[k]);
						grid[queue[front].x + xx[k]][queue[front].y + yy[k]] = 1;
						cnt++; 
					}
				}
				front++;
			}
			result++;
		}
	}
	if (cnt != N*M) result = 0;
	printf("%d\n", result-1);
	return 0;
}