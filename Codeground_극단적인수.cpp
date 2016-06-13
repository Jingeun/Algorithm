#include <stdio.h>
int main(void) {
	setbuf(stdout, NULL);
	int T, test_case ,n, x, cnt, half;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		printf("Case #%d\n", test_case);
		x = 0;
		scanf("%d", &n);
		cnt = 2;
		while (n > x){
			x += cnt;
			cnt *= 2;
		}
		cnt /= 2;
		while (n > 0){
			half = x - cnt/2 + 1;
			if (n == 1) { printf("%d\n", 4); break; }
			else if (n == 2) { printf("%d\n", 7); break; }
			if (half > n) {
				printf("4");
				n -= cnt / 2;
			}
			else {
				printf("7");
				n -= cnt;
			}
			x -= cnt;
			cnt /= 2;	
		}
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}