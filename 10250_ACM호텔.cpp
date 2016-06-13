#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int H, W, num;
		scanf("%d %d %d", &H, &W, &num);
		printf("%d\n", ((num%H == 0 ? H : num%H) * 100) + ((num%H == 0) ? num / H : num / H + 1));
	}
}