#include <stdio.h>

int main(){
	int itr, nCount;		/* ������ �׽�Ʈ ���̽� */
	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */
	for (itr = 0; itr<nCount; itr++){
		printf("#testcase%d\n", itr + 1);
		long long int D, H, M;
		scanf("%lld %lld %lld", &D, &H, &M);
		long long int result = 0;
		result = M - 11 + (H - 11) * 60 + (D - 11) * 1440;
		printf("%lld\n", result >= 0 ? result : -1);
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}