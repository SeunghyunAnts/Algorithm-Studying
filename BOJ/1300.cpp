/*
    BOJ 1300 (https://www.acmicpc.net/problem/1300)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, k, left, right, ans = -1;
	ll bk = 0;

	// init
	{
		cin >> n;
		cin >> k;
		left = 1 * 1;
		right = n * n;
	}

	// calc
	while(left <= right) {
		// if cur == b[k], there are k - 1 numbers < b[k]
		ll cur = (left + right) / 2;
		ll cnt = 0;

		for(int i = 1; i <= n; i++) {
			ll curCnt = cur / i;
			cnt += min(curCnt, n);
		}


		if(cnt < k) {
			// K th number is less than cur
			left = cur + 1;
		} else {
			ans = cur;
			right = cur - 1;
		}
	}


	// output
	{
		cout << ans;
	}

	return 0;
}