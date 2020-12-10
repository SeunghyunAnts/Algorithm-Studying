#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;	// <= 200

	cin >> tc;

	while(tc--) {
		ll n;
		ll cnt = 0;

		cin >> n;

		ll cur = 0;
		for(int i = 0; i <= n / 2; i++) {
			cnt += (cur * i);
			cur += 8;
		}

		cout << cnt << "\n";
	}
	return 0;
}