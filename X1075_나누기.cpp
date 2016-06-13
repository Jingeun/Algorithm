#include <stdio.h>
#include <stdlib.h>

int main()
{
	char n[11];
	int f;
	int tmp, result;

	scanf("%s", &n);
	scanf("%d", &f);

	tmp = atoi(n);

	if (tmp%f == 0)
		result = 0;
	else {
		tmp = tmp - tmp % 100;
		for (int i = 0; i < 100; i++) {
			if ((tmp + i) % f == 0) {
				result = i;
				break;
			}
		}
	}

	printf("%02d\n", result);
}