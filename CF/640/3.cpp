#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll tc;
	ll n, k;
	cin >> tc;

	while(tc--) {
		cin >> n >> k;

		ll l = 0;
		ll h = 2000000000 + 1;
		ll ret = -1;

		while(l <= h) {
			ll cur = (l + h) / 2;
			if(cur % n == 0) cur++;
			ll ncnt = cur / n;	// cur에 n의 배수가 몇개 들어가있는지 구함
			
			if(cur - ncnt == k) {
				ret = cur;
				break;
			} else if(cur - ncnt < k) {
				// 순서가 더 작을 경우
				l = cur + 1;
			} else {
				h = cur - 1;
			}
		}

		cout << ret << "\n";
	}

	return 0;
}