#include <stdio.h>
#define swap(x,y) {int t=x;x=y;y=t;}
int main(){
	int a[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < 3; i++)
		for (int j = i; j >=0; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);

	char tmp;
	for (int i = 0; i < 3; i++){
		scanf("%c", &tmp);
		while (tmp == '\n')
			scanf("%c", &tmp);
		printf("%d ", a[tmp - 'A']);
	}
}