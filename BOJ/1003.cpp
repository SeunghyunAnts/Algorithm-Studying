/*
    BOJ 1003 (https://www.acmicpc.net/problem/1016)
*/

#include <bits/stdc++.h>
using namespace std;

int dp[41];
int dpcount[40][2];

int fib(int n) {
	if (n == 0) {
		dp[n] = 0;
		dpcount[0][0] = 1;
		return 0;
	} else if (n == 1) {
		dp[n] = 1;
		dpcount[1][1] = 1;
		return 1;
	}
	
	if (dp[n] != 0) return dp[n];
	
	dp[n] = fib(n-1) + fib(n-2);
	dpcount[n][0] = dpcount[n-1][0] + dpcount[n-2][0];
	dpcount[n][1] = dpcount[n-1][1] + dpcount[n-2][1];
	return dp[n];
}

int fib(int n) {
	if(n == 0) {
		
	}
}

int main(void) {
	int n;
	
	// 입력
	cin >> n;

	// DP로 메모라이징
	fib(40);

	while(n--) {
		// 확인하려는 값 x
		int x;

		// 입력
		cin >> x;

		// 출력
		cout << dpcount[x][0] << " " << dpcount[x][1] << "\n";
	}

	return 0;
}