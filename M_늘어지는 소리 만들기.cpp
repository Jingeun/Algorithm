#include <stdio.h>
#include <string.h>

char str[21];
int d[21];
void init(){
	for (int i = 0; i < 21; i++){
		str[i] = '0';
		d[i] = 0;
	}
}
int main(){
	int itr, nCount;		/* ������ �׽�Ʈ ���̽� */
	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */
	for (itr = 0; itr<nCount; itr++){
		printf("#testcase%d\n", itr + 1);
		init();
		scanf("%s", &str);
		int cnt, tmp;
		scanf("%d", &cnt);
		for (int i = 0; i < cnt; i++){
			scanf("%d", &tmp);
			d[tmp]++;
		}
		int length = strlen(str)+1;
		for (int i = 0; i < length; i++){
			if (d[i] != 0){
				for (int j = 0; j < d[i]; j++)
					printf("-");
			}
			if (i!=length)
				printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}