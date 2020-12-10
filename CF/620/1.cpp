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
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if((y - x) % (a + b) == 0) {
			cout << (y - x) / (a + b) << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}