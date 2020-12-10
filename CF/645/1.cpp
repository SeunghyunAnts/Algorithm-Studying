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
		int n, m;
		cin >> n >> m;
		if(n * m % 2 == 0) {
			cout << n * m / 2 <<"\n";
		} else {
			cout << n * m / 2 + 1 << "\n";
		}
	}

	return 0;
}