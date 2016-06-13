#include <stdio.h>
int N, M, cnt, max;
char grid[11][11];
void init(){
	int i, j;
	for (i = 0; i < 11; i++)
		for (j = 0; j < 11; j++)
			grid[i][j] = 0;
	cnt = max = 0;
}
void print(){
	int i, j;
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++)
			printf("%c ", grid[i][j]);
		printf("\n");
	}
	printf("\n");
}
void solve(int x, int y){
	if (grid[x][y] == 'x' || grid[x-1][y-1]=='-' || grid[x-1][y+1]=='-' || grid[x][y-1]=='-' || grid[x][y+1]=='-')
		return;
	cnt++;
	grid[x][y] = '-';
	print();
	//위쪽
	if (x - 1>0 && grid[x - 1][y] == '.')
		solve(x - 1, y);
	//왼쪽
	if (y - 2>0 && grid[x][y - 2] == '.')
		solve(x, y - 2);
	//오른쪽
	if (y + 2 <= M && grid[x][y + 2] == '.')
		solve(x, y + 2);

	if (x+1<=N && y - 1 >0 && grid[x+1][y - 1] == '.')
		solve(x+1, y-1);
	if (x + 1<=N && grid[x + 1][y] == '.')
		solve(x + 1, y);
	if (x + 1<=N && y +1 <=M && grid[x + 1][y + 1] == '.')
		solve(x + 1, y + 1);

	if (max < cnt) max = cnt;
	grid[x][y] = '.';
	cnt--;

}
int main(){
	int tmp = 0, i, j;
	int testcase;
	scanf("%d", &testcase);
	while (testcase--){
		init();
		scanf("%d %d ", &N, &M);
		for (i = 1; i <= N; i++)
			for (j = 1; j <= M; j++){
				scanf("%c", &grid[i][j]);
				while (grid[i][j] == '\n' || grid[i][j] == '\0')
					scanf("%c", &grid[i][j]);

			}

		/*for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				if(grid[i][j]=='.') solve(i,j);*/

		for (i = 1; i <= M; i++)
				if (grid[1][i] == '.') 
					solve(1, i);
		printf("%d\n", max);
	}
	return 0;
}