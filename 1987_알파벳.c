#include <stdio.h>
int count = 0, alpha[26], R, C, max = 0;
char grid[21][21];
void DFS(int i, int j){
	if (i < 0 || i >= R || j < 0 || j >= C || alpha[grid[i][j]-'A']==1) return;
	alpha[grid[i][j] - 'A'] = 1;
	count++;
	if (max < count) max = count;
	DFS(i - 1, j);
	DFS(i, j - 1);
	DFS(i + 1, j);
	DFS(i , j + 1);
	count--;
	alpha[grid[i][j] - 'A'] = 0;
}

int main(){
	int i, j;
	char tmp;

	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++){
			scanf("%c", &tmp);
			while (tmp == '\n' || tmp == '\0')
				scanf("%c", &tmp);
			grid[i][j] = tmp;
		}
	DFS(0,0);
	printf("%d\n", max);
	return 0;
}