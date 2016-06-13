#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	int num = 1, cnt = 1;
	while (num < x) num += cnt++;
	num -= --cnt;
	if (cnt == 0) cnt = 1;
	int sub = x - num, aa = (cnt - sub) == 0 ? 1 : cnt - sub;
	if (cnt % 2 == 0) printf("%d/%d\n", 1 + sub, aa);
	else printf("%d/%d\n", aa, 1 + sub);
}