#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		ll n, m, curtime, curMinT, curMaxT;
		bool cansolve;

		cin >> n >> m;
		curtime = 0, curMinT = m, curMaxT = m, cansolve = true;

		for(int i = 0; i < n; i++) {
			ll t, l ,h, dif;
			cin>> t >> l >> h;
			
			dif = t - curtime;	// 최대 변경 가능한 온도
			curtime = t;

			if(h < curMinT) {
				if(h < curMinT - dif) {
					// 도달 불가능한 경우
					cansolve = false;
				} else {
					curMaxT = h;
					curMinT = max(curMinT - dif, l);
				}
			} else if(curMaxT < l) {
				if(curMaxT + dif < l) {
					cansolve = false;
				} else {
					curMinT = l;
					curMaxT = min(curMaxT + dif, h);
				}
			} else {
				curMinT = max(curMinT - dif, l);
				curMaxT = min(curMaxT + dif, h);
			}
		}
		if(cansolve) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}