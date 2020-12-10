#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	int twopow[30 + 1] = {0};

	twopow[0] = 1;
	for(int i = 1; i < 31; i++) {
		twopow[i] = twopow[i - 1] * 2;
		twopow[i - 1]--;
	}
	twopow[30]--;

	cin >> tc;

	while(tc--) {
		int n;
		int res = 0;
		cin >> n;

		for(int k = 2; k < 31; k++) {
			int cur = twopow[k];
			if(n % cur == 0) {
				res = n / cur;
				break;
			}
		}

		cout << res << "\n";
	}

	return 0;
}