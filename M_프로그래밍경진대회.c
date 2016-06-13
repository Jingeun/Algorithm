#include <stdio.h>

int data[300001];

int main(void) {
	int T,i,N, max, count;
	int test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//	이 부분에서 알고리즘 프로그램을 작성하십시오.
		//init
		for (i = 0; i < 300001; i++) data[i] = 0;
		max = count = 0;
		scanf("%d", &N);
		for (i = 0; i < N; i++){
			scanf("%d", &data[i]);
			if (i == 0 || max<data[i]) max = data[i];
		}
		for (i = 0; i<N; i++){
			if (data[i] + N >= max+1)count++;
		}

		//	이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}