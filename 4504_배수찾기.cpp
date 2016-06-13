#include <stdio.h>

int main() {
	int n, tmp;
	scanf("%d", &n);
	while (1) {
		scanf("%d", &tmp);
		if (tmp == 0) break;
		printf("%d is ", tmp);
		if (tmp%n != 0) printf("NOT ");
		printf("a multiple of %d.\n", n);
	}
}