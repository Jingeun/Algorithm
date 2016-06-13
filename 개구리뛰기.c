#include <stdio.h>
#include <string.h>

int grid[1000000], count;
void init(){
	memset(grid, 0, sizeof(grid));
	count = 0;
}
int main(){
	setbuf(stdout, NULL);
	int T, N, K, i, tmp, pretmp, sum;
	int test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		init();
		sum = tmp = pretmp = 0;
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			scanf("%d", &grid[i]);
		scanf("%d", &K);
		for (i = 1; i <= N; i++){
			tmp = grid[i];
			grid[i] = grid[i] - pretmp;
			pretmp = tmp;
			if (grid[i] > K){
				count = -2;
				break;
			}
		}
		if (count != -2){
			for (i = 1; i <= N; i++){
				sum += grid[i];
				if (sum > K){
					count++;
					sum = grid[i];
				}
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", count+1);
	}
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}