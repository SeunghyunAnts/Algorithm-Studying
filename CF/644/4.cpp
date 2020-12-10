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
		ll n, k;
		ll ret = -1;

		cin >> n >> k;

		if(n <= k) {
			ret = 1;
		} else {
			ll mn = 1000000000;
			ll cur;
			for(int i = 1; i * i <= n; i++) {
				if(n % i == 0) {
					// n = i * (n / i)
					cur = i;
					if(n / cur < mn && cur <= k) {
						mn = n / cur;
					}
					cur = n / i;
					if(n / cur < mn && cur <= k) {
						mn = n / cur;
					}
				}
			}
			ret = mn;
		}

		cout << ret << "\n";
	}

	return 0;
}