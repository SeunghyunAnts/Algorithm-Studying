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
		string num;
		ll n, k, cnt = 1;

		cin >> num >> k;
		
		n = stoll(num);

		while(cnt < k) {
			ll minD = 10, maxD = -1;
			for(int ptr = 0; ptr < num.size(); ptr++) {
				int tmp = num[ptr] - '0';
				if(tmp < minD) {
					minD = tmp;
				}
				if(maxD < tmp) {
					maxD = tmp;
				}
			}

			if(minD * maxD == 0) {
				break;
			}

			// cnt + 1 th ak ==
			n = n + minD * maxD;
			num = to_string(n);
			cnt++;
		}

		cout << n << "\n";
	}

	return 0;
}