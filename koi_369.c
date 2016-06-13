#include <stdio.h>

int checking(long long int num){
	int tmp = 0;
	while (num != 0){
		tmp = num % 10;
		if (tmp % 3 == 0 || tmp % 6 == 0 || tmp % 9 == 0)
			return 1;
		num /= 10;
	}
	return 0;
}

int main(){
	long long int start, end, i, count=0;
	
	scanf("%lld %lld", &start, &end);
	for (i = start; i <= end; i++){
		if (checking(i) == 1)
			count++;
	}
	printf("%lld\n", count % 20150523);
	return 0;
}