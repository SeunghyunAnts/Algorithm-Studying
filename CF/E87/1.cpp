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
		ll a, b, c, d;

		cin >> a >> b >> c >> d;

		ll ret = 0;
		ll cur = a;
		ll cnt = 0;
		ll cd = c - d;
		
	
		ret += b;
		cur -= b;

		if(ret >= a) {
			cout << ret << "\n";
			continue;
		}

		if(cd <= 0) {
			cout << -1 << "\n";
			continue;
		}
		
		if(cur % cd == 0) {
			cnt = cur / cd;
		} else {
			cnt = cur / cd + 1;
		}
		
		ret += c * cnt;
		cout << ret << "\n";
	}

	return 0;
}