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

	int n;
	cin >> n;
	int dp[n + 1] = {0};
	dp[1] = 1;
	dp[2] = 3;

	for(int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}
	cout << dp[n] << "\n";

	return 0;
}