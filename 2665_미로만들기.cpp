#include <stdio.h>
typedef struct node { int x, y; }node;
node Wqueue[999], Bqueue[999];
int grid[53][53];
int Wfront = 0, Wrear = 0, Bfront = 0, Brear = 0, count = 2;
void print(int n) {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++)
			printf("%2d ", grid[i][j]);
		printf("\n");
	}
	printf("\n");
}
void enqueue(int x, int y, char m) {
	if (m == 'W') {
		Wqueue[Wrear].x = x;
		Wqueue[Wrear++].y = y;
		grid[x][y] = count;
	}else {
		Bqueue[Brear].x = x;
		Bqueue[Brear++].y = y;
		grid[x][y] = count * -1;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &grid[i][j]);
			if (grid[i][j] == 0) grid[i][j] = -1;
		}
	int xx[] = { -1,0,1,0 }, yy[] = { 0,-1,0,1 }, check = 1;
	enqueue(1, 1, 'W');
	print(n);
	while (check) {
		while (Wfront != Wrear && check) {
			int size = Wrear - Wfront;
			for (int i = 0; i < size && check; i++) {
				for (int j = 0; j < 4; j++) {
					int x = Wqueue[Wfront].x + xx[j], y = Wqueue[Wfront].y + yy[j];
					if (x == n && y == n) { check = 0; break; }
					if (grid[x][y] == 1) enqueue(x, y, 'W');
					else if (grid[x][y] == -1) enqueue(x, y, 'B');
				}
				Wfront++;
			}
		}
		print(n);
		Wfront = Wrear = 0;
		while (Bfront != Brear && check) {
			int x = Bqueue[Bfront].x, y = Bqueue[Bfront].y;
			enqueue(x, y, 'W');
			Bfront++;
		}
		Bfront = Brear = 0;
		count++;
		print(n);
	}
	printf("%d\n", count - 3);
	return 0;
}