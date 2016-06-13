#include <stdio.h>
int visit[51], t[51][51], result[51];
void init() {
	for (int i = 0; i < 51; i++) visit[i] = 0;
}
int BFS(int n, int target) {
	int cnt = 0, rear = 0, front = 0, q[99];
	q[rear++] = target;
	while (front != rear) {
		int size = rear - front;
		for (int k = 0; k < size; k++) {
			for (int i = 1; i <= n; i++) {
				if (visit[i] == 0 && t[q[front]][i] == 1) {
					visit[i] = 1;
					q[rear++] = i;
				}
			}
			front++;
		}
		cnt++;
	}
	return cnt-1;
}
int main() {
	int n, a, b, min = 99999999;
	scanf("%d", &n);
	while (scanf("%d %d", &a, &b) && a != -1 && b != -1) {
		t[a][b] = 1;
		t[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		init();
		result[i] = BFS(n, i);
		if (min > result[i]) min = result[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (result[i] == min) cnt++;
	printf("%d %d\n", min, cnt);
	for (int i = 1; i <= n; i++)
		if (min == result[i]) printf("%d ", i);
	return 0;
}