#include <stdio.h>
#include <Math.h>
#include <string.h>

int check_len(int num){
	int count = 0;
	while (num!=0){
		count++;
		num /= 10;
	}
	return count;
}

int main(){
	int plus, minus;
	int N, n, i, tmp, btncount = 0;
	int btn[10];

	scanf("%d", &N);
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &tmp);
		btn[tmp] = 1;
		btncount++;
	}

	if (btncount == 0){
		printf("%d\n", check_len(N));
	}else if (btncount == 10){
		printf("%d\n", abs(N - 100));
	}else{

	}


}