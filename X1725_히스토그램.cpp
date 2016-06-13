#include <stdio.h>
#include <stack>
using namespace std;

#define MAXN 500001
int N, Number[MAXN];
stack<int> Stack;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &Number[i]);

	int ans = 0, cnt = 1;
	while (cnt <= N) {
		if (Stack.empty() || Number[Stack.top()] <= Number[cnt]) {
			Stack.push(cnt++);
		}
		else {
			int index = Stack.top();
			Stack.pop();

			int height = Number[index];
			int right = cnt - 1;
			int left = Stack.empty() ? 1 : Stack.top() + 1;

			int now = Number[index] * (right - left + 1);
			if (ans < now) ans = now;
		}
	}
	while (!Stack.empty()) {
		int index = Stack.top();
		Stack.pop();

		int height = Number[index];
		int right = N;
		int left = Stack.empty() ? 1 : Stack.top() + 1;

		int now = Number[index] * (right - left + 1);
		if (ans < now) ans = now;
	}
	printf("%d", ans);
}