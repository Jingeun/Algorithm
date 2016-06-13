#include <stdio.h>
#include <stdlib.h>
#define swap(x,y){int t=x;x=y;y=t;}
int n, paper[105][2], max = 0, dp[105];
int comp(const void *aa, const void *bb){
	int *a = (int *)aa, *b = (int *)bb;
	if (a[0] > b[0]) return 1;
	else if (a[0] < b[0]) return -1;
	else return a[1] > b[1] ? 1 : -1;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d %d", &paper[i][0], &paper[i][1]);
		if (paper[i][1] > paper[i][0])
			swap(paper[i][1], paper[i][0]);
	}
	qsort(paper, n+1, sizeof(paper[0]), comp);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++){
			if (paper[i][1] >= paper[j][1] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				if (max < dp[i]) max = dp[i];
			}
		}
	printf("%d\n", max);
	return 0;
}