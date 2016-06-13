#include <stdio.h>

int data[31], tmp[31];

int main(){
	int testcase, N, i, j, check, count;

	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &data[i]);
		count = 0;
		while (1) {
			check = 1;
			for (i = 0; i < N; i++) {
				if (data[i] % 2 == 1) data[i]++;
				data[i] = tmp[i] = data[i] / 2;
			}

			for (i = 0; i < N - 1; i++) 
				if (data[i] != data[i + 1]) { 
					check = 0; break; 
				}

			if (check) { printf("%d\n", count); break; }

			count++;
			for (i = 0; i < N - 1; i++) 
				data[i] += tmp[i + 1];
			data[N - 1] += tmp[0];
		}
	}
	return 0;
}