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
		int a, b;
		int l;

		cin >> a >> b;

		if(a < b) {
			if(2 * a < b) {
				l = b;
			} else {
				l = 2 * a;
			}
		} else {
			if(2 * b < a) {
				l = a;
			} else {
				l = 2 * b;
			}
		}

		cout << l * l << "\n";
	}

	return 0;
}