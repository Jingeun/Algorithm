#include <stdio.h>

typedef struct node{
	int x, y;
}node;
node queue[10003];

int front, rear, countA, countB;
char gridA[103][103], gridB[103][103];

node newnode(int x, int y){
	node tmp; tmp.x = x; tmp.y = y;
	return tmp;
}

void BFS(int x, int y, int choice){
	//0-일반  1- 적록색
	int i, xx[] = { 1, 0, -1, 0 }, yy[] = { 0,-1,0,1};
	char tmp;
	if (choice == 0){
		tmp = gridA[x][y];
		gridA[x][y] = '0';
		countA++;
	}else{
		tmp = gridB[x][y];
		gridB[x][y] = '0';
		countB++;
	}
	front = rear = 0;
	queue[rear++] = newnode(x, y);

	while ((rear - front) != 0){
		for (i = 0; i < 4; i++){
			if (choice == 0){
				if (gridA[queue[front].x + xx[i]][queue[front].y + yy[i]] == tmp){
					gridA[queue[front].x + xx[i]][queue[front].y + yy[i]] = '0';
					queue[rear++] = newnode(queue[front].x + xx[i], queue[front].y + yy[i]);
				}
			}else{
				if (tmp == 'R' || tmp == 'G'){
					if (gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] == 'R' || gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] == 'G'){
						gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] = '0';
						queue[rear++] = newnode(queue[front].x + xx[i], queue[front].y + yy[i]);
					}
				}else{
					if (gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] == tmp){
						gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] = '0';
						queue[rear++] = newnode(queue[front].x + xx[i], queue[front].y + yy[i]);
					}
				}
			}
		}
		front++;
	}
}

int main(){
	int N, i, j;
	char tmp;
	scanf("%d", &N);
	for (i = 0; i <= N + 1; i++)
		for (j = 0; j <= N + 1; j++){
			gridA[i][j] = '0';
			gridB[i][j] = '0';
		}
	countA = countB = 0;

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%c", &tmp);
			while (tmp == '\n' || tmp == '\0')
				scanf("%c", &tmp);
			gridA[i][j] = tmp;
			gridB[i][j] = tmp;
		}
	}

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			if (gridA[i][j] != '0') BFS(i, j, 0);
			if (gridB[i][j] != '0') BFS(i, j, 1);
		}
	}

	printf("%d %d\n", countA, countB);
	return 0;
}