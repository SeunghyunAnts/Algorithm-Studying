#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, m;

	cin >> n >> m;

	vector<ll> dif;
	ll s = 0;

	for(int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		s += a;
		dif.push_back(a - b);
	}

	sort(dif.rbegin(), dif.rend());

	for(int i = 0; i <= n; i++) {
		if(s <= m) {
			cout << i;
			return 0;
		} else {
			if(i == n) continue;
			s -= dif[i];
		}
	}

	cout << "-1";

	return 0;
}