#include <stdio.h>

int main()
{
	int n, d[20] = { 0 }, i, j, t;

	d[1] = d[2] = d[3] = 1;
	for (i = 1; i <= 11; i++)
		for (j = 1; j <= 3; j++)
			d[i + j] += d[i];

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		printf("%d\n", d[t]);
	}
}