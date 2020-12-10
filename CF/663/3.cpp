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


ll p(int n) {
	ll ans = 1;
	for(int i = 0; i < n; i++) {
		ans *= 2;
		ans = ans % (1000000000 + 7);
	}
	return ans;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	ll ans = 1;
	ll moder = 1000000000 + 7;

	for(ll i = 1; i <= n; i++) {
		ans = ((ans % moder) * (i % moder)) % moder;
	}

	cout << (ans - p(n - 1) + 1000000000 + 7) % (1000000000 + 7);

	return 0;
}