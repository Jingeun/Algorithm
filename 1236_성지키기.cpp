#include <stdio.h>
int x[51], y[51];
int main() {
	int N, M;
	char tmp;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &tmp);
			while(tmp=='\n') scanf("%c", &tmp);
			if (tmp == 'X') {
				x[i]++;
				y[j]++;
			}
		}
	}
	int xx = 0, yy = 0;
	for (int i = 0; i < N; i++)
		if (x[i] == 0) xx++;
	for (int i = 0; i < M; i++)
		if (y[i] == 0) yy++;

	printf("%d\n", xx > yy ? xx : yy);
	return 0;
}