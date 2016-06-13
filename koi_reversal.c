#include <stdio.h>

int main(){
	int data[21], tmp[21];
	int i, j, start, end;
	for (i = 1; i < 21; i++)
		data[i] = i;

	for (i = 0; i < 10; i++){
		scanf("%d %d", &start, &end);
		for (j = start; j <= end; j++)
			tmp[j - start] = data[j];
		for (j = start; j <= end; j++)
			data[j] = tmp[end - j];
	}
	for (i = 1; i < 21; i++)
		printf("%d ", data[i]);
	printf("\n");
}