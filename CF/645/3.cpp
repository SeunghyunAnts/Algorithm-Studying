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
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (x2 - x1) * (y2 - y1) + 1 << "\n";
	}

	return 0;
}