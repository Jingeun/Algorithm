#include <stdio.h>
int grid[62][62];
int N, M, B, W;
int xx[] = { -1, -1, 0, 1, 1, 1, 0, -1 }, yy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void init(){
	for (int i = 0; i < 62; i++)
		for (int j = 0; j < 62; j++)
			grid[i][j] = (i == 0 || j == 0 || i == N+1 || j == N+1)?-1:0;

	grid[N / 2][N / 2] = 2;
	grid[N / 2 + 1][N / 2 + 1] = 2;
	grid[N / 2 + 1][N / 2] = 1;
	grid[N / 2][N / 2 + 1] = 1;
	B = 2, W = 2;
}
void win(int x, int y, int c){
	grid[x][y] = c;
	if (c == 1){ B++; W--; }
	else{ W++; B--; }
}
int check(int pos, int x, int y, int c){
	if (grid[x + xx[pos]][y + yy[pos]] == c) return 1;
	if ((c == 1 && grid[x + xx[pos]][y + yy[pos]] == 2) ||
		(c == 2 && grid[x + xx[pos]][y + yy[pos]] == 1)){
		if(check(pos, x + xx[pos], y + yy[pos], c)){
			win(x + xx[pos], y + yy[pos], c);
			return 1;
		}
	}
	return 0;
}
void solve(int x, int y, int c){
	for (int i = 0; i < 8; i++){
		/* 검은색 돌 놓기, 주변 흰색 탐색, 햐안색 돌 놓기, 주변 검은색 탐색 */
		if ((c == 1 && grid[x + xx[i]][y + yy[i]] == 2) || (c == 2 && grid[x + xx[i]][y + yy[i]] == 1)){
			if (check(i, x + xx[i], y + yy[i], c))
				win(x + xx[i], y + yy[i], c);
		}
	}
}
int main(){
	int itr, nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	for (itr = 0; itr<nCount; itr++)	{
		printf("#testcase%d\n", itr + 1);
		scanf("%d %d", &N, &M);
		init();
		//1-B, 2-W
		for (int i = 0; i < M; i++){
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			grid[y][x] = c;
			if (c == 1) B++;
			else W++;
			solve(y, x, c);
		}
		printf("%d %d\n", B, W);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}