#include <stdio.h>

#define max 32
char grid[max][max][max];
int count, front, rear, check;

typedef struct node{
	int x, y, f;
}node;
node queue[1000001];

node newnode(int i, int j, int k){
	node tmp;
	tmp.f = i;tmp.x = j;tmp.y = k;
	grid[i][j][k] = '*';
	return tmp;
}

void BFS(){
	int size, i, j;
	int xx[] = { 0, -1, 0, 1 }, yy[] = { 1, 0, -1, 0 };
	while (front!=rear && check){
		size = rear - front;
		for (i = 0; i < size && check; i++){
			for (j = 0; j < 4 && check; j++){
				if (grid[queue[front].f][queue[front].x + xx[j]][queue[front].y + yy[j]] == 'E') { check = 0; break; }
				else if (grid[queue[front].f][queue[front].x + xx[j]][queue[front].y + yy[j]] == '.')
					queue[rear++] = newnode(queue[front].f, queue[front].x+xx[j], queue[front].y+yy[j]);
			}

			if (grid[queue[front].f + 1][queue[front].x][queue[front].y] == 'E') { check = 0;  break; }
			else if (grid[queue[front].f + 1][queue[front].x][queue[front].y] == '.')
				queue[rear++] = newnode(queue[front].f + 1, queue[front].x, queue[front].y);
			else if (grid[queue[front].f - 1][queue[front].x][queue[front].y] == '.')
				queue[rear++] = newnode(queue[front].f - 1, queue[front].x, queue[front].y);

			front++;
		}
		count++;
	}
}

void init(){
	int i, j, k;
	for (i = 0; i < max; i++)
	for (j = 0; j < max; j++)
	for (k = 0; k < max; k++)
		grid[i][j][k] = '0';
	count = front = rear = 0;
	check = 1;
}

int main(){
	int L, R, C, i,j,k;
	char tmp;
	while (1){
		scanf("%d %d %d", &L, &R, &C);
		init();
		if (L == 0 && R == 0 && C == 0) break;
		for (i = 1; i <= L; i++)
			for (j = 1; j <= R; j++)
			for (k = 1; k <= C; k++){
				scanf("%c", &tmp);
				while (tmp == '\n' || tmp == '\0')
					scanf("%c", &tmp);
				grid[i][j][k] = tmp;
				if (grid[i][j][k] == 'S') queue[rear++] = newnode(i, j, k);
			}
		BFS();
		if (check == 0) printf("Escaped in %d minute(s).\n", count);
		else printf("Trapped!\n");
	}
	return 0;
}