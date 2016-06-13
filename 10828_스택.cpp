#include <stdio.h>
#include <string.h>
int stack[10010], top = 0;
int main() {
	int n;
	char m[10];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", m);
		if (strcmp(m, "push")==0) {
			int push;
			scanf("%d", &push);
			stack[++top] = push;
		}else if (strcmp(m, "pop") == 0) {
			printf("%d\n", top==0?-1:stack[top--]);
		}else if (strcmp(m, "top") == 0) {
			printf("%d\n", top==0?-1:stack[top]);
		}else if (strcmp(m, "size") == 0) {
			printf("%d\n", top);
		}else if (strcmp(m, "empty") == 0) {
			printf("%d\n", top == 0 ? 1 : 0);
		}
	}
	return 0;
}