#include <stdio.h>
#include <stdlib.h>
int table[6][3];
int comp(const void *aa, const void *bb){
	int *a = (int *)aa, *b = (int *)bb;
	if (a[0] < b[0]) return 1;
	else if (a[0] > b[0]) return -1;
	else return a[2] > b[2] ? 1 : -1;
}
int main(){
	int testcase = 4, n, result = 0;
	while (testcase--){
		for (int i = 0; i < 6; i++)
			scanf("%d %d %d", &table[i][0], &table[i][1], &table[i][2]);
		qsort(table, 6, sizeof(table[0]), comp);
		
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 6; j++){
				if (i != j && table[i][0] != 0 && table[j][2] != 0) {  }
				if (i != j && table[i][1] != 0 && table[j][1] != 0) { table[i][1]--; table[j][1]--; }
			}
		}
		int result = 1;
		for (int i = 0; i < 6 && result; i++)
			if (table[i][0] != 0 || table[i][1] != 0 || table[i][2] != 0) result = 0;
		printf("%d\n", result);
	}
	return 0;
}