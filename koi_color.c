#include <stdio.h>

int grid[1002][1002], count[101];

int main(){
	int n, i, j, k;
	int sx, sy, ex, ey;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++){
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		for (j = sx; j < sx+ex; j++)
			for (k = sy; k < sy+ey; k++)
				grid[j][k] = i;
	}
	for (i = 0; i < 1002; i++)
		for (j = 0; j < 1002; j++){
			if (grid[i][j] != 0)
				count[grid[i][j]]++;
		}

	for (i = 1; i <= n; i++)
		printf("%d\n", count[i]);
	return 0;
}