#include <stdio.h>
int car1[2], car2[2], crime[1005][2], car[1005], result = 0;
int abs(int x){
	return x > 0 ? x : x*-1;
}
int distance(int x, int y, int car){
	return (car == 1) ? abs(car1[0] - x) + abs(car1[1] - y) : abs(car2[0] - x) + abs(car2[1] - y);
}
void solve(int i, int t){
	if (i >= t || car[i]!=0) return;
	int car1_distance = distance(crime[i][0], crime[i][1], 1);
	int car2_distance = distance(crime[i][0], crime[i][1], 2);
	if (car1_distance > car2_distance){
		result += car2_distance;
		car2[0] = crime[i][0];
		car2[1] = crime[i][1];
		car[i] = 2;
	}else if (car1_distance < car2_distance){
		result += car1_distance;
		car1[0] = crime[i][0];
		car1[1] = crime[i][1];
		car[i] = 1;
	}else{
		solve(i + 1, t);
	}
}
int main(){
	int n, t;
	scanf("%d", &n);
	scanf("%d", &t);
	car1[0] = 1; car1[1] = 1;
	car2[0] = n; car2[1] = n;
	for (int i = 0; i < t; i++)
		scanf("%d %d", &crime[i][0], &crime[i][1]);
	for (int i = 0; i < t;i++)
		solve(i, t);
	printf("%d\n", result);
	for (int i = 0; i < t;i++)
		printf("%d\n", car[i]);
	return 0;
}