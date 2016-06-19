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
	int itr, nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
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
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}