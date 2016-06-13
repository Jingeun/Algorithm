#include <stdio.h>
#include <stdlib.h>
int data[100001][2];
int comp(const void* aa, const void* bb){
	int *a = (int *)aa, *b = (int *)bb;
	if (a[1] > b[1]) return 1;
	else if (a[1] < b[1]) return -1;
	else return a[0] > b[0] ? 1 : -1;
}
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &data[i][0], &data[i][1]);
	qsort(data, N, sizeof(data[0]), comp);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", data[i][0], data[i][1]);
	return 0;
}