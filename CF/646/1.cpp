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
		int n, x, ecnt = 0, ocnt = 0;
		cin >> n >> x;
		for(int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if(num%2 == 0) ecnt++;
			else ocnt++;
		}

		if(x == 1) {
			if(0 < ocnt) cout << "YES\n";
			else cout << "NO\n";
		} else if(x == 2) {
			if(0 < ocnt && ocnt % 2 != 0) cout << "YES\n";
			else cout << "NO\n";
		} else {
			if(ocnt == 0 || ocnt % 2 == 0) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}

	return 0;
}