#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;	// <= 10^4

	cin >> tc;

	while(tc--) {
		int n;	// array size
		int s;	// array sum

		cin >> n >> s;

		if(n == 1) {
			cout << "0\n";
		} else if(n == 2) {
			cout << s << "\n";
		} else {
			// 2 < n
			cout << 2 * s << "\n";
		}
	}
	return 0;
}