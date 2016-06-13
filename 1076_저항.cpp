#include <stdio.h>
#include <string.h>
char data[10][10] = {"black", "brown", "red", "orange", "yellow", "green", "blue","violet","grey","white"};
int check(char tmp[10]) {
	for (int i = 0; i < 10; i++)
		if (strcmp(data[i], tmp) == 0)
			return i;
	return -1;
}

int main() {
	char tmp[10];
	long long int result = 0;
	scanf("%s", tmp);
	result = check(tmp) * 10;
	scanf("%s", tmp);
	result += check(tmp);
	scanf("%s", tmp);
	int c = check(tmp);
	long long int mul = 1;
	for (int i = 0; i < c; i++)
		mul *= 10;
	printf("%lld\n", result*mul);
	return 0;
}