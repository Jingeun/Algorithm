#include <stdio.h>
int count = 0;
long long int remain[200001], quotient[200001];
int main() {
	int n, menu;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &menu);
		if (menu == 1) {
			long long int a, b;
			scanf("%lld %lld", &a, &b);
			quotient[count] = a;
			remain[count++] = b;
		}
		else {
			bool check = true;
			long long int t;
			scanf("%lld", &t);
			long long int max = 1000000*(-1000000000000) - 1000000000001;
			for (int i = 0; i < count; i++) {
				long long int tmp = quotient[i] * t + remain[i];
				if (max < tmp)
					max = tmp;
			}
			printf("%lld\n", check?max:(max*-1));
		}

	}
}