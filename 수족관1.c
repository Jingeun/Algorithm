#include <stdio.h>
int data[40001];
int hole[20001];

int main() {
	int n1, n2, i, j, min, result = 0;
	int r1, r2, r3, r4, end;
	scanf("%d", &n1);

	for (i = 0; i < n1; i++) {
		scanf("%d %d", &r1, &r2);
		if (i != 0 && i != n1 - 1) {
			scanf("%d %d", &r3, &r4);
			for (j = r1; j < r3; j++)
				data[j] = r2;
			i++;
		}
		if (i == n1 - 1) end = r1;
	}

	scanf("%d", &n2);
	for (i = 0; i < n2; i++) {
		scanf("%d %d %d %d", &r1, &r2, &r3, &r4);
		hole[i] = (r1 + r3) / 2;
	}

	while (n2--) {
		if (data[hole[n2]] == 0) continue;
		//왼쪽체크
		min = data[hole[n2]];
		for (i = hole[n2] - 1; i >= 0; i--) {
			if (min <= data[i])
				data[i] -= min;
			else {
				min = data[i];
				data[i] = 0;
			}
		}

		//오른쪽체크
		min = data[hole[n2]];
		for (i = hole[n2] + 1; i < end; i++) {
			if (min <= data[i])
				data[i] -= min;
			else {
				min = data[i];
				data[i] = 0;
			}
		}
		data[hole[n2]] = 0;
	}

	for (i = 0; i < end; i++)
		result += data[i];
	printf("%d\n", result);

	return 0;
}