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

	ll n, ans;
	cin >> n;

	ans = n;

	for(ll i = 2; i * i <= n; i++) {
		if(n == 1) break;
		if(n % i == 0) {
			ans /= i;
			ans *= (i - 1);

			while(n > 1 && n % i == 0) {
				n /= i;
			}
		}
	}
	if(n > 1) {
		ans /= n;
		ans *= (n - 1);
	}

	cout << ans << "\n";

	return 0;
}