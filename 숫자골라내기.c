#include <stdio.h>

int data[_INTEGRAL_MAX_BITS];
int result[40];
void init(){
	int i;
	for (i = 0; i < 3000001; i++)
		data[i] = -1;
	for (i = 0; i < 40; i++)
		result[i] = 0;
}

void XOR(int num){
	int count = 0;
	while (num != 0){
		result[count] = (result[count] == num % 2) ? 0 : 1;
		num /= 2;
		count++;
	}
}

int main(void) {
	int T, N, i, j, tmp,count;
	int test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//	이 부분에서 알고리즘 프로그램을 작성하십시오.
		scanf("%d", &N);
		init();
		
		for (i = 0; i < N; i++)
			scanf("%d", &data[i]);

		for (i = 0; i < N; i++){
			if (data[i] != -1){
				tmp = data[i];
				count = 0;
				for (j = i; j < N; j++){
					if (tmp == data[j]){
						data[j] = -1;
						count++;
					}
				}
				if (count % 2 == 1) 
					XOR(tmp);
			}
		}

		//	이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);

		for (i = 0,count=1,tmp=0; i < 40; i++,count*=2)
			tmp += result[i] * count;
		printf("%d\n", tmp);

	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}