#include <stdio.h>
#include <stdlib.h>

#define min -999999999
typedef int(*comp)(const void*, const void*);
typedef struct node{ int x, y, k; }node;

int compare(node *a, node *b){ return a->k > b->k ? 1 : 0; }

node building[100001];
int data[100001], rear = 0, front = 0;

void init(){
	for (int i = 0; i < 100001; i++){
		building[i].x = -1;
		building[i].y = -1;
		building[i].k = 0;
	}
}
int distance(int i, int j){
	int x = building[i].x - building[j].x;
	int y = building[i].y - building[j].y;
	if (x < 0) x *= -1;
	if (y < 0) y *= -1;
	return 10 / (x + y);
}

int main(){
	int itr, nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	for (itr = 0; itr<nCount; itr++)	{
		printf("#testcase%d\n", itr + 1);
		init();
		int N, W, K;
		scanf("%d %d %d", &N, &W, &K);
		for (int i = 0; i < N; i++)
			scanf("%d %d %d", &building[i].x, &building[i].y, &building[i].k);
		qsort((void*)building, N, sizeof(node), (comp)compare);
		int cnt = 0;
		for (int k = 0; k < K;k++){
			//1년마다 내구도...
			rear = front = 0;
			for (int i = 0; i < N; i++){
				building[i].k--;
				if (building[i].k == 0){
					building[i].k = -1;
					data[rear++] = i;
					cnt++;
				}
			}
			//폭발 돌리기
			while (rear - front != 0){
				for (int i = cnt; i < N; i++){
					building[i].k -= distance(data[front], i);
					if (building[i].k <= 0){
						building[i].k = -1;
						data[rear++] = i;
						cnt++;
					}
				}
				front++;
			}
		}
		printf("%d\n", N - cnt);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}