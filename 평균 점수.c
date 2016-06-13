#include <stdio.h>
int data[6];
int main() {
	int i, sum=0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &data[i]);
		if (data[i] < 40) data[i] = 40;
		sum += data[i];
	}
	printf("%d\n", sum / 5);
}