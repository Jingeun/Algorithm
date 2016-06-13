#include <stdio.h>

int GCD(int a, int b){
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main(){
	int A1, A2, A, B1, B2, B, gcd;
	scanf("%d %d %d %d", &A1, &B1, &A2, &B2);

	A = A1*B2 + A2*B1;
	B = B1*B2;

	gcd = (A>B)?GCD(A, B):GCD(B,A);
	printf("%d %d\n", A / gcd, B / gcd);

	return 0;
}