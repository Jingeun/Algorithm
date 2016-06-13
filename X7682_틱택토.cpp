#include <stdio.h>
#include <string.h>
char grid[9];
char checking2() {
	if (grid[2] != '.' && grid[2] == grid[4] && grid[4] == grid[6]) return grid[2];
	if (grid[0] != '.' && grid[0] == grid[4] && grid[4] == grid[8]) return grid[0];
	for (int i = 2; i >=0; i--)
		if (grid[0 + i] != '.' && grid[0 + i] == grid[3 + i] && grid[3 + i] == grid[6 + i]) return grid[0 + i];
	for (int i = 6; i >= 0; i -=3)
		if (grid[0 + i] != '.' && grid[0 + i] == grid[1 + i] && grid[1 + i] == grid[2 + i]) return grid[0 + i];
	return '.';
}
char checking1() {
	for (int i = 0; i < 7;i += 3)
		if (grid[0 + i] != '.' && grid[0 + i] == grid[1 + i] && grid[1 + i] == grid[2 + i]) return grid[0 + i];
	for (int i = 0; i < 3; i++)
		if (grid[0 + i] != '.' && grid[0 + i] == grid[3 + i] && grid[3 + i] == grid[6 + i]) return grid[0 + i];
	if (grid[0] != '.' && grid[0] == grid[4] && grid[4] == grid[8]) return grid[0];
	if (grid[2] != '.' && grid[2] == grid[4] && grid[4] == grid[6]) return grid[2];
	return '.';
}
int main(){
	while (1) {
		scanf("%s", grid);
		if (strcmp(grid, "end") == 0) break;
		int length = strlen(grid);
		int cnt_X = 0, cnt_O = 0, cnt_P = 0;
		for (int i = 0; i < length; i++) {
			if (grid[i] == 'X') cnt_X++;
			else if (grid[i] == 'O') cnt_O++;
			else cnt_P++;
		}
		bool check = false;
		if (cnt_X < 6 && cnt_O < 5 && (cnt_X >= 3 || cnt_O >= 3)) {
			char flag = checking1();
			if (flag == '.') check = true;
			else if (flag == 'X' && cnt_X == cnt_O + 1) {
				if(flag == checking2())
					check = true;
			}
			else if (flag == 'O' && cnt_O == cnt_X) {
				char asdf = checking2();
				if(flag == asdf)
					check = true;
			}
		}

		printf("%s\n", check == true ? "valid" : "invalid");
	}
	return 0;
}