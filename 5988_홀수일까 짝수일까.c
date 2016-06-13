#include <stdio.h>

int main() {
	char str[62];
	int n, i, p;
	scanf("%d\n", &n);
	while (n--) {
		scanf("%s", &str);
		for (i = 0; i < 62; i++) {
			if (str[i + 1] == '\0' || str[i + 1] == '\n') {
				printf((str[i] - '0') % 2 == 0 ? "even\n" : "odd\n");
				break;
			}
		}
	}
}