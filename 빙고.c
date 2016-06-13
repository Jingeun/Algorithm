#include <stdio.h>

typedef struct node {
	int x, y;
}node;
node pos[26];
int x[6], y[6];
int main() {
	int i, j, k, count, tmp, result = 0, cnt = 0;
	
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++) {
			scanf("%d", &tmp);
			pos[tmp].x = i;
			pos[tmp].y = j;
		}
		
	for (i = 1; i <= 5; i++)
		for (j = 1; j <= 5; j++) {
			cnt++;
			scanf("%d", &tmp);
			x[pos[tmp].x]++;
			y[pos[tmp].y]++;
			if (pos[tmp].x == pos[tmp].y) x[5]++;
			if (pos[tmp].x + pos[tmp].y == 4) y[5]++;
			for (count = 0, k = 0; k < 6; k++) {
				if (x[k] == 5) count++;
				if (y[k] == 5) count++;
			}
			if (count >= 3 && result == 0)
				result = cnt;
		}

	printf("%d\n", result);
	return 0;
}