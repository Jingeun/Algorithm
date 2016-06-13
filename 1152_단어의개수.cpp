#include <stdio.h>
#include <string.h>
char data[1000001];
int main() {
	int result = 0, i = 0, flag = 0;
	fgets(data, 10000001, stdin);
	int length = strlen(data);
	for (int i = 0; i < length; i++) {
		//공백이 아니면 flag = 1
		if (data[i] != ' ')
			flag = 1;
		else {
			result++;
			flag = 0;
		}
	}
	if (flag == 1) result++;
	printf("%d\n", result);
}