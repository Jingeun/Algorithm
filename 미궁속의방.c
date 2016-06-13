#include <stdio.h>

int hashing[400001], xx, yy;
void init(int n){
	hashing[0] = 1;
	int count = 1;
	for (int i = 1; i <= n + 1; i++, count++)
		hashing[i] = hashing[i - 1] + (count - 1);
	count--;
	for (int i = n + 1; i<2 * n; i++, count--)
		hashing[i] = hashing[i - 1] + (count - 1);
	xx = yy = 0;
}
int solve(int n) {
	//홀수 : 오른쪽 위, 짝수 : 왼쪽 아래
	if ((xx + yy) % 2 == 0){	//오른쪽 위
		return (xx + yy + 1) <= n ? hashing[xx + yy + 1] + yy : hashing[xx + yy + 1] - (xx + 1 - n);
	}else{	//왼쪽 아래
		return (xx + yy + 1) <= n ? hashing[xx + yy + 1] + xx : hashing[xx + yy + 1] + n - yy - 1;
	}
}
int main(void) {
	int T, n, k, count;
	int test_case;
	char tmp;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//	이 부분에서 알고리즘 프로그램을 작성하십시오.
		scanf("%d %d", &n, &k);
		init(n);
		count = 1;
		for (int i = 0; i<k; i++){
			scanf("%c", &tmp);
			while (tmp == '\n')
				scanf("%c", &tmp);
			if (tmp == 'D')xx++;
			else if (tmp == 'R') yy++;
			else if (tmp == 'U') xx--;
			else yy--;
			count += solve(n);
		}

		//	이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}