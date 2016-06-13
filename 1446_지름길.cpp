#include <stdio.h>
typedef struct node { int S, E, L; }node;
node road[100005];
int roadData[10005];
void swap(int x, int y) {
	node tmp = road[x];
	road[x] = road[y];
	road[y] = tmp;
}
int main() {
	int n, D, cnt = 0, result[2];

	scanf("%d %d", &n, &D);
	for (int i = 0; i < n; i++) {
		int s, e, l;
		scanf("%d %d %d", &s, &e, &l);
		if (e - s >= l) {
			road[cnt].S = s;
			road[cnt].E = e;
			road[cnt++].L = l;
		}
	}
	for (int i = 1; i < 10005; i++) roadData[i] = 10005;

	//Á¤·Ä
	for (int i = 0; i < cnt; i++) 
		for (int j = 1; j < cnt-i; j++) {
			if (road[j].S < road[j - 1].S)
				swap(j, j - 1);
			else if (road[j].S == road[j-1].S && road[j].E < road[j - 1].E)
			swap(j, j - 1);
		}

	for (int i = 0; i < cnt; i++) {
		if (road[i].E > D) continue;
		else if (road[i].S > D) break;
		if (roadData[road[i].S] == 10005) {
			int check = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (road[j].E < road[i].S) {
					roadData[road[i].S] = roadData[road[j].E] + (road[i].S - road[j].E);
					check = 0;
					break;
				}
			}
			if (check) roadData[road[i].S] = road[i].S;
		}
		if (roadData[road[i].E] > road[i].L + roadData[road[i].S]) {
			roadData[road[i].E] = road[i].L + roadData[road[i].S];
			result[0] = road[i].E;
			result[1] = road[i].L + roadData[road[i].S];
		}
	}
	printf("%d\n", (result[0] == D) ? roadData[D] : result[1] + (D - result[0]));
}