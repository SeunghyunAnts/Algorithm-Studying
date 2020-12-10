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

	ll h, x, ans = 0;
	ll dp[1000000 + 1] = {0};
	ll div = 1000000000 + 7;

	cin >> h >> x;
	
	dp[0] = 1;
	for(int i = 1; i <= h; i++) {
		dp[i] = dp[i - 1] * x;
		dp[i] = dp[i] % div;
	}

	for(ll i = 1; i <= h; i++) {
		ll snowball;
		cin >> snowball;
		ans += dp[i] * snowball;
		ans = ans % div;
	}

	cout << ans;

	return 0;
}