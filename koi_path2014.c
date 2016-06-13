#include <stdio.h>

int check(int x, int y){
	int data[16][16] = { 0 };
	int i, j;
	for (i = 1; i <= x; i++){
		for (j = 1; j <= y; j++){
			if (i == 1 || j == 1) data[i][j] = 1;
			else
				data[i][j] = data[i - 1][j] + data[i][j - 1];
		}
	}
	return data[x][y];
}

int main(){
	int x, y, k, count=0, mod;
	scanf("%d %d %d", &x, &y, &k);
	if (k == 0)
		count = check(x, y);
	else if (k%y == 0){
		count = check(k/y, y);
	}else{
		count = check((k / y) + 1, k%y) * check(x - (k / y), y - k%y + 1);
	}
	printf("%d\n", count);
	return 0;
}