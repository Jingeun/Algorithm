#include <stdio.h>

int data[300001];

int main(void) {
	int T,i,N, max, count;
	int test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
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

		//	�� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}