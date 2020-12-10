#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		ll n, cnt = 0, c = 1, cp = 0;
		cin >> n;
		vector<ll> memo;
		while(c <= n) {
			memo.push_back(pow(2, cp + 1) - 1);
			c *= 2;
			cp += 1;
		}

		c /= 2;
		cp--;
		cnt += memo[cp];

		ll rest = n - c;
		while(0 < rest) {
			ll cur = 1, curp = 0;
			while(cur <= rest) {
				cur *= 2;
				curp++;
			}
			cur = cur / 2;
			curp--;
			rest -= cur;
			cnt += memo[curp];
		}

		cout << cnt << "\n";
	}

	return 0;
}