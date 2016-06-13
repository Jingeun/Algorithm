#include <stdio.h>

int data1[5001];
int data2[5001][5001];

void init(){
	int i, j;
	for (i = 0; i < 5001; i++){
		data1[i] = 0;
		for (j = 0; j < 5001; j++)
			data2[i][j] = 0;
	}
}

void print(){
	int i, j;
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++)
			printf("%d ", data2[i][j]);
		printf("\n");
	}
	printf("\n");
}
int solve(int num){
	return 0;
}

int main(void) {
	int T, N, i, j,k;
	int test_case, count, check;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//	이 부분에서 알고리즘 프로그램을 작성하십시오.
		init();
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &data1[i]);



		//	이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}
	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}