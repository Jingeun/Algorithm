#include <stdio.h>
#include <stdlib.h>
int d[100001];
int comp(const void *a, const void *b) {
	return *(int *)a < *(int *)b;
}
int main(){
	int itr, nCount;		/* ������ �׽�Ʈ ���̽� */
	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */
	for (itr = 0; itr<nCount; itr++){
		printf("#testcase%d\n", itr + 1);
		int n;
		long long int result = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &d[i]);
			result += d[i];
		}
		qsort(d, n, sizeof(d[0]), comp);
		for (int i = 0; i < n; i+=3)
			result -= d[i + 2];
		printf("%lld\n", result);
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}