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
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		init();
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &data1[i]);



		//	�� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}
	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}