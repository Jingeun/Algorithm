#include <stdio.h>

int data[1000001];

int main(){
	int start, end, count, tmp;
	int n, i, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &data[i]);
	scanf("%d", &k);
	start = count = 0;
	end = n - 1;
	while (start<end){
		tmp = data[start] + data[end];
		if (tmp == k){
			count++;
			start++;
			end--;
		}
		else if (tmp > k) end--;
		else start++;
	}
	printf("%d\n", count);
}