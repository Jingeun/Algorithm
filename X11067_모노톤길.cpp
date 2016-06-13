#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int t=x;x=y;y=t;}
int asdf[32000][32000];
int grid[100002][2], check[100002], order[100002];
int comp(const void *aa, const void *bb) {
	int *a = (int *)aa, *b = (int *)bb;
	if (a[0] > b[0]) return 1;
	else if (a[0] < b[0]) return -1;
	else return a[1] > b[1] ? 1 : -1;
}
void init() {
	for (int i = 0; i < 100002; i++) {
		check[i] = 0;
		order[i] = 0;
	}
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int n, checkCnt = 0;
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &grid[i][0], &grid[i][1]);
			check[grid[i][0]]++;
		}
		qsort(grid, n+1, sizeof(grid[0]), comp);
		for (int i = 1, flag = 0, cnt = 1; i <= n; i++) {
			flag = 0;
			if (check[grid[i][0]] > 1) {
				int max = grid[i+check[grid[i][0]]-1][1];
				int min = grid[i][1];
				if (i!=1 && grid[i - 1][1] == max) { //¾Æ·¡
					for (int j = i + check[grid[i][0]] - 1, c=i; j >= i; j--,c++)
						order[c] = j;
					flag = 1;
					i += check[grid[i][0]] - 1;
				}
			}
			if (!flag)
				order[i] = i;	
		}
		int t;
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {
			int tmp;
			scanf("%d", &tmp);
			printf("%d %d\n", grid[order[tmp]][0], grid[order[tmp]][1]);
		}
	}
}