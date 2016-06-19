#include <stdio.h>

int main(){
	int itr, nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	for (itr = 0; itr<nCount; itr++)	{
		printf("#testcase%d\n", itr + 1);

	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}