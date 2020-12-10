/*
    BOJ 2688 (https://www.acmicpc.net/problem/2688)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	// memo[k][i] : 맨 앞자리수가 k이고, 길이가 i인
	// 줄어들지 않는 수의 개수
	ll memo[9 + 1][64 + 1] = {0};
	for(int i = 1; i < 64 + 1; i++) {
		for(int k = 9; 0 <= k; k--) {
			if(i == 1) {
				memo[k][i] = 1;
			} else if(k == 9) {
				memo[k][i] = memo[k][i - 1];
			} else {
				memo[k][i] = memo[k + 1][i] + memo[k][i - 1];
			}
		}
	}

	while(tc--) {
		int n;
		ll sum = 0;
		cin >> n;
		for(int i = 0; i < 10; i++) sum += memo[i][n];
		cout << sum << "\n";
	}

	return 0;
}