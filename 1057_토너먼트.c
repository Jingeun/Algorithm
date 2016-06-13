#include <stdio.h>
int check(int x, int y) {
	if (x % 2 == 1 && x + 1 == y) return 0;
	if (y % 2 == 1 && y + 1 == x) return 0;
	return 1;
}
int main() {
	int count = 1;
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	while (check(x,y)) {
		x = (x % 2 == 0) ? x / 2 : (x + 1) / 2;
		y = (y % 2 == 0) ? y / 2 : (y + 1) / 2;
		count++;
	}
	printf("%d\n", count);
}