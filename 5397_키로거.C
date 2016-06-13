#include <stdio.h>
#include <string.h>
int s1, s2;
char data[1000010], stack1[1000010], stack2[1000010];
int main() {
	int n, i, length;
	scanf("%d", &n);
	while (n--) {
		s1 = s2 = 0;
		scanf("%s", &data);
		length = strlen(data);
		for (i = 0; i < length; i++){
			if (data[i] == '<') {
				if (s1 != 0)
					stack2[s2++] = stack1[--s1];
			}else if (data[i] == '>') {
				if (s2 != 0) 
					stack1[s1++] = stack2[--s2];
			}else if (data[i] == '-') {
				if (s1 != 0)
					s1--;
			}else 
				stack1[s1++] = data[i];
		}

		for (i = 0; i < s1; i++) printf("%c", stack1[i]);
		for (i = s2-1; i >=0; i--) printf("%c", stack2[i]);
		printf("\n");
	}
}