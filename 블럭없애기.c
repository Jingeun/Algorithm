#include <stdio.h>

int grid[100002];

int main(void) {
	int T, i, N, past, ppast, check, count, cnt, tmp;
	int test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			scanf("%d", &grid[i]);
		grid[0] = 0;
		grid[N + 1] = 0;
		check = count = 0;

		while (N>2){
			ppast = grid[0];
			cnt = 1;
			for (i = 1; i <= N; i++){
				past = grid[i];
				if (grid[i] != 0){
					if (grid[i] <= ppast && grid[i] <= grid[i + 1])
						tmp = grid[i] - 1;
					else if (grid[i] > ppast || grid[i] > grid[i + 1])
						tmp = (ppast < grid[i + 1]) ? ppast : grid[i + 1];
				}
				if ((tmp == 0 && grid[cnt - 1] != 0) || tmp != 0)
					grid[cnt++] = tmp;
				ppast = past;
			} 
			N = (grid[cnt] == 0)?cnt:cnt+1;
			grid[N] = 0;
			count++;
		}
		//	�� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}