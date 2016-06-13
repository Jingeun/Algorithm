#include <stdio.h>
#include <string.h>

int grid[1002][1002];
int count, pos, x, y;

void init(){
	memset(grid, -1, sizeof(grid));
	count = pos = 0;
	x = y = 1;
}

void checkDirection(){
	if (grid[x][y] % 3 == 1 ){
		switch (pos){
		case 0: pos = 1; break;
		case 1: pos = 0; break;
		case 2: pos = 3; break;
		case 3: pos = 2; break;
		}
	}
	else if (grid[x][y] % 3 == 2){
		switch (pos){
		case 0: pos = 3; break;
		case 1: pos = 2; break;
		case 2: pos = 1; break;
		case 3: pos = 0; break;
		}
	}
}

int main(void) {
	setbuf(stdout, NULL);
	int T, i, j, N;
	int test_case;
	char tmp;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

		init();
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++){
				scanf("%c", &tmp);
				while (tmp == '\n' || tmp == '\0')
					scanf("%c", &tmp);
				grid[i][j] = tmp - '0';
			}

		/* pos
			0 -> 오른쪽
			1 -> 위쪽
			2 -> 왼쪽
			3 -> 아래쪽
		*/

		while (grid[x][y] != -1){

			if (grid[x][y] % 3 == 1 || grid[x][y] % 3 == 2){
				if (grid[x][y] == 1){
					count++;
					grid[x][y] = 4;
				}
				else if (grid[x][y] == 2){
					count++;
					grid[x][y] = 5;
				}
				checkDirection();
			}

			switch (pos){
			case 0: y++; break;
			case 1: x--; break;
			case 2: y--; break;
			case 3: x++; break;
			}
		}
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}