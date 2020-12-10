#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll n, k, s, cur = 0;

	cin >> n >> k >> s;

	ll maxmove = (n - 1);

	if(maxmove * k < s) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";

	
	bool goback = true;

	if(s % k == 0) {
		ll dif = s / k;
		while(k--) {
			if(goback) {
				cout << 1 + dif << " ";
			} else {
				cout << 1 << " ";
			}
			goback = !goback;
		}
	} else {
		// k % s != 0
		ll dif = s / k;
		ll res = s % k;
		ll a = k - 1;

		if(a % 2 == 0) {
			while(a--) {
				if(goback) {
					cout << 1 + dif << " ";
				} else {
					cout << 1 << " ";
				}
				goback = !goback;
			}
			cout << 1 + dif + res;
		} else {
			a--;
			while(a--) {
				if(goback) {
					cout << 1 + dif << " ";
				} else {
					cout << 1 << " ";
				}
				goback = !goback;
			}

			// 먼저 멀리갓다가 돌아옴
			cout << 1 + dif + res << " ";
			cout << 1 + res;
		}
	}

	

	return 0;
}