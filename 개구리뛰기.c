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
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", count+1);
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}