#include <stdio.h>

typedef struct node{
	int x, y, cnt;
}node;
char grid[32][32];
int N, M, queueCnt, grassCnt;
node q[1000], grass[1000];
void print(){
	for (int i = 0; i < N + 2; i++){
		for (int j = 0; j < M + 2; j++){
			printf("%2c ", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printc(char data[32][32]){
	for (int i = 0; i < N + 2; i++){
		for (int j = 0; j < M + 2; j++){
			printf("%2c ", data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void init(){
	for (int i = 0; i < 32; i++)
		for (int j = 0; j < 32; j++)
			grid[i][j] = (i == 0 || j == 0 || i == M + 1 || j == N + 1) ? '1' : '0';
	grassCnt = queueCnt= 0;
}
void push(int x, int y, int c){
	q[queueCnt].x = x;
	q[queueCnt].y = y;
	q[queueCnt++].cnt = c;
}
void grassPush(int x, int y, int c){
	grass[grassCnt].x = x;
	grass[grassCnt].y = y;
	grass[grassCnt++].cnt = c;
}
void grassfire(){
	int max = 0, xx[] = {-1,0,1,0}, yy[] = {0,1,0,-1};
	char copy[32][32];
	for (int i = 0; i < 32; i++) for (int j = 0; j < 32; j++) copy[i][j] = grid[i][j];
	queueCnt = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (copy[i][j] != '#' && copy[i][j] != '1'){
				push(i, j, 0);
				copy[i][j] = '#';
				int cnt = 1;
				while (queueCnt!=0){
					node t = q[--queueCnt];
					char tmp = grid[t.x][t.y];
					for (int k = 0; k < 4; k++)
						if (copy[t.x + xx[k]][t.y + yy[k]] == tmp){
							copy[t.x + xx[k]][t.y + yy[k]] = '#';
							push(t.x + xx[k], t.y + yy[k],0);
							cnt++;
						}
					printc(copy);
				}
				printc(copy);
				grassPush(i, j, cnt);
				if (max < cnt) max = cnt;
			}
		}
	}

	for (int i = 0; i < grassCnt; i++){
		if (grass[i].cnt == max){
			queueCnt = 0;
			push(grass[i].x, grass[i].y, 0);
			char tmp = grid[grass[i].x][grass[i].y];
			grid[grass[i].x][grass[i].y] = '#';
			while (queueCnt != 0){
				node t = q[--queueCnt];
				for (int k = 0; k < 4; k++)
					if (grid[t.x + xx[k]][t.y + yy[k]] == tmp){
						grid[t.x + xx[k]][t.y + yy[k]] = '#';
						push(t.x + xx[k], t.y + yy[k], 0);
					}
			}
		}
	}
}
void D(){
	grassfire();
	for (int i = 1; i <= M; i++){
		int cnt = 0, flag = 0;
		for (int j = N; j > 0; j--){
			if (grid[j][i] == '#'){
				flag = 1; cnt++;
			} else if (grid[j][i] != '#' && flag) {	/* 내리기 */
				for (int l = j; l > 0; l--) grid[l + cnt][i] = grid[l][i];
				for (int l = 1; l <= cnt; l++) grid[l][i] = '#';
				j = N-cnt; flag = cnt = 0;
			}
		}
	}
}
void L(){
	for (int i = 1; i <= N; i++){
		int cnt = 0, flag = 0;
		for (int j = 1; j <= M; j++){
			if (grid[i][j] == '#'){
				flag = 1; cnt++;
			}
			else if (grid[i][j] != '#' && flag) {	/* 내리기 */
				for (int l = j; l <= M; l++) grid[i][l - cnt] = grid[i][l];
				for (int l = M; l > M-cnt; l--) grid[i][l] = '#';
				flag = cnt = 0;
			}
		}
				//print();
	}
}
void R(){
	for (int i = N; i > 0; i--){
		int cnt = 0, flag = 0;
		for (int j = M; j > 0; j--){
			if (grid[i][j] == '#'){
				flag = 1; cnt++;
			}
			else if (grid[i][j] != '#' && flag) {	/* 내리기 */
				for (int l = j; l > 0; l--) grid[i][l + cnt] = grid[i][l];
				for (int l = 1; l <= cnt; l++) grid[i][l] = '#';
				j = M - cnt + 1; flag = cnt = 0;
			}
		}
				//print();
	}
}
int main(){
	int itr, nCount, Q;		/* 문제의 테스트 케이스 */
	char tmp[31];
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	for (itr = 0; itr<nCount; itr++){
		printf("#testcase%d\n", itr + 1);
		scanf("%d %d %d", &N, &M, &Q);
		init();
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++){
				scanf("%c", &grid[i][j]);
				while (grid[i][j]=='\n')
					scanf("%c", &grid[i][j]);
			}
		print();
		for (int i = 0; i < Q; i++){
			char m;
			scanf("%c", &m);
			while (m == '\n')
				scanf("%c", &m);
			if (m == 'D') D();
			else if (m == 'L') L();
			else if (m == 'R') R();
			else if (m == 'U'){
				for (int j = 0; j < M; j++)
					scanf("%s", &tmp);
			}
			print();
		}

	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}