#include <stdio.h>

int main(){
	int i, N, cluster, file[1001], tmp;
	long long int result = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &file[i]);
	scanf("%d", &cluster);

	for (i = 0; i < N; i++)
		result += cluster * ((file[i] % cluster == 0) ? (file[i] / cluster) : (file[i] / cluster) + 1);

	printf("%lld\n", result);
	return 0;
}