#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while(tc--) {
		ll mindif = 10000000;	// move cnt
		ll mincnt = 10000000;
		
		long double h, c, t;	// hot, cool, target
		long double cur = h;
		
		cin >> h >> c >> t;

		long double e = (h + c) / 2;
		
		if(e == t) {
			cout << 2 << "\n";
			continue;
		}

		mindif = abs(e - t);
		mincnt = 1;

		ll le = 1, ri = 1000000000000+1;

		while(le <= ri) {
			ll cur = (le + ri) / 2;
			long double cur_t;
			ll a, b;

			if(cur % 2 == 0) {
				a = cur / 2;
				b = cur / 2;
			} else {
				a = cur / 2 + 1;
				b = cur / 2;
			}

			cur_t = (((long double)a * h) + ((long double)b * c)) / cur;

			cout << le << " " << ri << " " << cur_t << "\n";

			if(abs(cur_t - t) < mindif) {
				mindif = abs(cur_t - t);
				mincnt = cur;
			} else if(abs(cur_t - t) == mindif) {
				if(mincnt > cur) {
					mincnt = cur;
				}
			}

			if(t < cur_t) {
				le = cur + 1;
			} else if(cur_t <= t) {
				ri = cur - 1;
			}
		}
	
		cout << mincnt << "\n";
	}

	return 0;
}