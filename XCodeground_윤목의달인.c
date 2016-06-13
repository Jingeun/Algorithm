#include <stdio.h>
#define DoubleToInteger 10000000000
long long int abs(long long int x){
	return x > 0 ? x : x*-1;
}
int main(void) {
	setbuf(stdout, NULL);
	int T, test_case,result[6], i, pos;
	double P;
	long long int PP, tmp, absValue, tmpabsValue, tmpArray[6], sum, cnt;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		printf("Case #%d\n", test_case);
		scanf("%lf", &P);
		PP = P * DoubleToInteger;
		tmp = sum = 0;
		cnt = 1;
		for (i = 0; i < 6; i++) 
			result[i] = 0;
		
		sum = tmp = (int)P * DoubleToInteger;
		pos = 3;
		cnt = 1;
		if (tmp == PP) result[(int)P]++;
		while (tmp != PP){
			if (tmp < PP) pos++;
			else if (tmp > PP){
				if (abs(tmp - PP) > 0.5 * DoubleToInteger) 
					pos--;
			}
			if (pos < 1) pos = 1;
			else if (pos > 5) pos = 5;
			cnt++;
			sum += pos*DoubleToInteger;
			tmp = sum / cnt;
			result[pos]++;
		}

		for (i = 1; i < 6; i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}