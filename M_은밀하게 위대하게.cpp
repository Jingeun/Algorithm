#include <stdio.h>

int main(){
	int itr, nCount;		/* ������ �׽�Ʈ ���̽� */
	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */
	for (itr = 0; itr<nCount; itr++)	{
		printf("#testcase%d\n", itr + 1);

	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}