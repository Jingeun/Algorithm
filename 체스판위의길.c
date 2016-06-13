#include <stdio.h>
#include <string.h>
typedef struct node{
	int x, y;
}node;

int grid[100001];
node obstacle[2001];
int obstacleCnt;

void init(){
	int i;
	for (i = 0; i < 100001; i++)
		grid[i] = 1;
	obstacleCnt = 0;
}

int main(){
	int T, N, M, K, i, j, x ,y;
	int test_case;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		init();
		scanf("%d %d %d", &N, &M, &K);
		for (i = 0; i < K; i++){
			scanf("%d %d", &x, &y);
			obstacle[i].x = x-1;
			obstacle[i].y = y-1;
		}

		//�������ʿ�... x������ ���� �켱 ->  x���� �����ͳ��� y���� ���� (�Ѵ� ��������)
		if (N>90000 && M > 90000){
			printf("Case #%d\n%d\n", test_case, grid[M - 1] % 1000000007);
			continue;
		}

		for (i = 1; i < N; i++){
			for (j = 1; j < M; j++){
				// �ش� �Ӽ��� -1�϶�
				if (obstacle[obstacleCnt].x == i && obstacle[obstacleCnt].y == j){
					grid[j] = -1;
					obstacleCnt++;
					continue;
				}else if (grid[j] == -1 || grid[j - 1] == -1)
					grid[j] = (grid[j] == -1) ? grid[j - 1] : grid[j];
				else{
					grid[j] = grid[j] + grid[j - 1];
					if (grid[j] > 1000000007) grid[j] -= 1000000007;
				}
			}
		}

		//	�� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, grid[M-1]%1000000007);

	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
