#include <stdio.h>
#include <string.h>
long long int flag, result;
char two[41], three[41];
void check(long long int a, long long int b) {
	if (a == b) { result = a; flag = 0; }
}
long long int Translate(int n, int length) {
	long long int i, c, result = 0;
	for (i = length - 1, c = 1; i >= 0; i--, c *= n)
		result += (n == 2 ? two[i] - '0' : three[i] - '0') * c;
	return result;
}
long long int pos(int j, int length) {
	long long int i, mul = 1;
	for (i = length - 1; i > j; i--) mul *= 3;
	return mul;
}
int main() {
	int itr, nCount, tmp;		/* 문제의 테스트 케이스 */
	long long int twoLength, threeLength, i, j, twoNum, threeNum, mul;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	for (itr = 0; itr<nCount; itr++) {
		printf("#testcase%d\n", itr + 1);
		scanf("%s", two);
		scanf("%s", three);
		twoLength = strlen(two);
		threeLength = strlen(three);
		flag = 1; result = -1;
		for (i = twoLength - 1; i >= 0 && flag; i--) {
			two[i] = two[i] == '0' ? '1' : '0';
			twoNum = Translate(2, twoLength);
			for (j = threeLength - 1; j >= 0; j--) {
				threeNum = threeNum = Translate(3, threeLength);
				mul = pos(j, threeLength);
				if (three[j] == '2') {
					check(twoNum, threeNum - mul);
					check(twoNum, threeNum - 2 * mul);
				}else if (three[j] == '1') {
					check(twoNum, threeNum + mul);
					check(twoNum, threeNum - mul);
				}else {
					check(twoNum, threeNum + mul);
					check(twoNum, threeNum + 2 * mul);
				}
			}
			two[i] = two[i] == '0' ? '1' : '0';
		}
		printf("%lld\n", result);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}