#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll a, b, c, d;

	cin >> a >> b >> c >> d;

	ll cur = 0;
	ll cnt = 0;

	for(ll z = c; z <= d; z++) {
		// then, x + y > z
		ll y = c;
		cur = z - y;

		if(cur < a) {
			cur = b - a + 1;
		} else {
			cur = b - cur;
		}
		if(cur <= 0) continue;

		if(y > z - a) {
			while(y > z - a && b <= y) {
				cnt += cur;
				y--;
			}

			cur--;
		}

		while(0 < cur && b <= y) {
			cnt += cur;
			y--;
			cur--;
		}
	}

	cout << cnt;

	return 0;
}