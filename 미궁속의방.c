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
	//Ȧ�� : ������ ��, ¦�� : ���� �Ʒ�
	if ((xx + yy) % 2 == 0){	//������ ��
		return (xx + yy + 1) <= n ? hashing[xx + yy + 1] + yy : hashing[xx + yy + 1] - (xx + 1 - n);
	}else{	//���� �Ʒ�
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
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
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

		//	�� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}