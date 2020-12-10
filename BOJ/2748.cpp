#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll dp[90 + 1] = {0};
	dp[1] = 1;

	for(int i = 2; i < 90 + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int n;
	cin >> n;

	cout << dp[n];

	return 0;
}