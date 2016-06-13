#include <stdio.h>
long long int abs(int length){
	long long int result = 1;
	for (int i = 0; i < length; i++)
		result *= 10;
	return result;
}
long long int solve(long long int n, int length){
	long long int result = 0;

	for (int i = length-1; i > 0; i--){
		long long int root = abs(i);
		int tmp = n / root;
		printf("%d", tmp);
	}


	return result;
}

int length(long long int n){
	int lng = 0;
	while (n != 0){
		lng++;
		n /= 10;
	}
	return lng;
}

int main(){
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++){
		printf("#testcase%d\n", itr + 1);
		long long int a, b;
		scanf("%lld %lld", &a, &b);

		long long int countA = solve(a < 0 ? a*(-1) : a, length(a));
		long long int countB = solve(b, length(b));

	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}