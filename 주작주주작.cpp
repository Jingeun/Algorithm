#include <stdio.h>
#include <string.h>

int answer[1000001], data[1000001];
int check() {

}
int main() {
	int n, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &answer[i]);

	for (int i = 0; i < n; i++) {
		if (answer[i] == i + 1) {
			result = -1;
			break;
		}
	}
	if (result != -1) {
		int max = answer[n-1];
		for (int i = n - 1; i >= 0; i--) {

		}
	}

	printf("%d\n", -1);
	
}