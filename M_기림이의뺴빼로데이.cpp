#include <stdio.h>

int main(){
	int itr, nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	for (itr = 0; itr<nCount; itr++){
		printf("#testcase%d\n", itr + 1);
		long long int D, H, M;
		scanf("%lld %lld %lld", &D, &H, &M);
		long long int result = 0;
		result = M - 11 + (H - 11) * 60 + (D - 11) * 1440;
		printf("%lld\n", result >= 0 ? result : -1);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}