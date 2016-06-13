#include <stdio.h>
#define n 4
#define point 15
typedef struct node { int x, y, pos; }node;
node data[n*n];
void newNode(int x, int y, int pos, int t){
	data[t].x = x;
	data[t].y = y;
	data[t].pos = pos;
}
int abs(int x) { return x < 0 ? x*-1 : x; }
int main() {
	int i, j, cnt = 0, result = 0;
	char tmp;
	
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) {
			scanf("%c", &tmp);
			while (tmp == '\n' || tmp == '\0')
				scanf("%c", &tmp);
			newNode(i, j, cnt++, tmp == '.' ? point : tmp - 'A');
		}

	while (data[point].pos != point) {
		node tmp = data[data[point].pos];
		result += abs(data[point].x - tmp.x) + abs(data[point].y - tmp.y);
		data[data[point].pos] = data[point];
		data[point] = tmp;
	}

	printf("%d\n", result);
} 